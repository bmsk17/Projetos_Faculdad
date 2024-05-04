import cv2

imagem = cv2.imread('pessoa.jpg')

nome= 'pessoa.jpg'

altura, largura, _ = imagem.shape
tamanho_arquivo = len(imagem)

print("Nome do Arquivo: ", nome)
print("Tamanho da imagem (largura x altura):", largura, "x", altura)
print("Tamanho do arquivo (bytes):", tamanho_arquivo)

imagem_rgb = cv2.cvtColor(imagem, cv2.COLOR_BGR2RGB)

paleta_cores = set()
for linha in imagem_rgb:
    for pixel in linha:
        paleta_cores.add(tuple(pixel))

print("Paleta de cores (cores únicas):", len(paleta_cores), "cores")

gamut = "RGB"

print("Gamut da imagem:", gamut)
