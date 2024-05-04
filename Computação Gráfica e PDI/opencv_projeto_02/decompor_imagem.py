import cv2
import numpy as np
import matplotlib.pyplot as plt

imagem = cv2.imread('pessoa.jpg')

imagem_rgb = cv2.cvtColor(imagem, cv2.COLOR_BGR2RGB)

canal_r = imagem_rgb[:,:,0]
canal_g = imagem_rgb[:,:,1]
canal_b = imagem_rgb[:,:,2]

hist_r = cv2.calcHist([canal_r], [0], None, [256], [0,256])
hist_g = cv2.calcHist([canal_g], [0], None, [256], [0,256])
hist_b = cv2.calcHist([canal_b], [0], None, [256], [0,256])

plt.figure(figsize=(10, 5))

plt.subplot(1, 3, 1)
plt.plot(hist_r, color='red')
plt.title('Histograma - Canal R')
plt.xlabel('Intensidade')
plt.ylabel('Frequência')

plt.subplot(1, 3, 2)
plt.plot(hist_g, color='green')
plt.title('Histograma - Canal G')
plt.xlabel('Intensidade')
plt.ylabel('Frequência')

plt.subplot(1, 3, 3)
plt.plot(hist_b, color='blue')
plt.title('Histograma - Canal B')
plt.xlabel('Intensidade')
plt.ylabel('Frequência')

plt.tight_layout()
plt.show()
