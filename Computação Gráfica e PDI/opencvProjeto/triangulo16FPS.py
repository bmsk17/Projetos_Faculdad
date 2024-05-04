import cv2
import numpy as np
import time

# Função para desenhar um triângulo colorido
def draw_colorful_triangle(img, center, size, color, angle):
    height, width, _ = img.shape
    half_size = size // 2
    points = np.array([[center[0], center[1] - half_size],
                       [center[0] - half_size, center[1] + half_size],
                       [center[0] + half_size, center[1] + half_size]], np.int32)
    points = points.reshape((-1, 1, 2))
    cv2.fillPoly(img, [points], color)

    # Aplica a transformação de rotação na imagem
    M = cv2.getRotationMatrix2D(center, angle, 1)
    rotated_img = cv2.warpAffine(img, M, (width, height))

    return rotated_img

# Cria uma lista de 16 imagens vermelhas para cada triângulo
images = [np.zeros((100, 100, 3), np.uint8) for _ in range(16)]

center = (50, 50)
size = 60

# Define cores para cada triângulo
colors = [
    (255, 0, 0), (0, 0, 255), (0, 255, 0), (255, 255, 0),
    (221, 0, 0), (0, 255, 255), (255, 0, 255), (0, 255, 0),
    (255, 0, 0), (0, 0, 255), (0, 255, 0), (255, 255, 0),
    (221, 0, 0), (0, 255, 255), (255, 0, 255), (0, 255, 0)
]

# Loop para girar os triângulos continuamente e medir o FPS
start_time = time.time()
frame_count = 0
while True:
    # Calcula o ângulo de rotação com base no tempo
    elapsed_time = time.time() - start_time
    if elapsed_time == 0:
        fps = 0
    else:
        angle = elapsed_time * 50  # Ajuste o fator de rotação conforme necessário

        # Desenha e rotaciona os 16 triângulos
        rotated_images = [draw_colorful_triangle(img.copy(), center, size, color, angle) for img, color in zip(images, colors)]

        # Combina as imagens horizontalmente
        combined_img = np.vstack(
            (np.hstack(rotated_images[:4]), np.hstack(rotated_images[4:8]), np.hstack(rotated_images[8:12]), np.hstack(rotated_images[12:]))
        )

        # Exibe o FPS nas imagens
        fps = frame_count / elapsed_time
        cv2.putText(combined_img, f"FPS: {fps:.2f}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)

        # Exibe a imagem na janela
        cv2.imshow('Colorful Rotating Triangles', combined_img)

    # Atualiza o contador de frames
    frame_count += 1

    # Verifica se a tecla 'q' foi pressionada para sair do loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Fecha a janela
cv2.destroyAllWindows()
