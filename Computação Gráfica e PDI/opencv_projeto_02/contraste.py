import cv2
import numpy as np
import matplotlib.pyplot as plt

imagem_colorida = cv2.imread('pessoa.jpg')

imagem_yuv = cv2.cvtColor(imagem_colorida, cv2.COLOR_BGR2YUV)

imagem_yuv[:,:,0] = cv2.equalizeHist(imagem_yuv[:,:,0])

imagem_equalizada = cv2.cvtColor(imagem_yuv, cv2.COLOR_YUV2BGR)

plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.imshow(cv2.cvtColor(imagem_colorida, cv2.COLOR_BGR2RGB))
plt.title('Imagem Original')
plt.axis('off')

plt.subplot(1, 2, 2)
plt.imshow(cv2.cvtColor(imagem_equalizada, cv2.COLOR_BGR2RGB))
plt.title('Imagem Equalizada')
plt.axis('off')

plt.tight_layout()
plt.show()
