import cv2
import numpy as np
import time

# Função para desenhar um triângulo texturizado
def draw_textured_triangle(img, center, size, texture, angle):
    height, width, _ = img.shape
    half_size = size // 2
    points = np.array([[center[0], center[1] - half_size],
                       [center[0] - half_size, center[1] + half_size],
                       [center[0] + half_size, center[1] + half_size]], np.int32)
    points = points.reshape((-1, 1, 2))

    # Criar uma máscara para o triângulo
    mask = np.zeros((height, width), np.uint8)
    cv2.fillPoly(mask, [points], 255)

    # Redimensionar a textura para as dimensões do triângulo
    resized_texture = cv2.resize(texture, (width, height))

    # Criar uma imagem preta para o triângulo texturizado
    textured_triangle = np.zeros_like(img)

    # Aplicar a textura usando a máscara
    textured_triangle[mask > 0] = resized_texture[mask > 0]

    # Aplica a transformação de rotação na imagem
    M = cv2.getRotationMatrix2D(center, angle, 1)
    rotated_textured_triangle = cv2.warpAffine(textured_triangle, M, (width, height))

    return rotated_textured_triangle

# Carregar uma textura (substitua 'sua_textura.jpg' pelo caminho da sua própria textura)
texture = cv2.imread('aa.jpg')

# Cria uma lista de 4 imagens para cada triângulo texturizado
textured_triangles = [np.zeros((100, 100, 3), np.uint8) for _ in range(4)]

center = (50, 50)
size = 60

# Define as cores para cada triângulo (usado para colorir a textura)
colors = [
    (255, 0, 0), (0, 0, 255),
    (0, 255, 0), (255, 255, 0)
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

        # Desenha e rotaciona os 4 triângulos texturizados
        rotated_textured_triangles = [draw_textured_triangle(img.copy(), center, size, texture, angle) for img in textured_triangles]

        # Combina as imagens em 2 linhas e 2 colunas
        combined_img = np.vstack((np.hstack(rotated_textured_triangles[:2]), np.hstack(rotated_textured_triangles[2:])))

        # Exibe o FPS nas imagens
        fps = frame_count / elapsed_time
        cv2.putText(combined_img, f"FPS: {fps:.2f}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)

        # Exibe a imagem na janela
        cv2.imshow('Textured Rotating Triangles', combined_img)

    # Atualiza o contador de frames
    frame_count += 1

    # Verifica se a tecla 'q' foi pressionada para sair do loop
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Fecha a janela
cv2.destroyAllWindows()
