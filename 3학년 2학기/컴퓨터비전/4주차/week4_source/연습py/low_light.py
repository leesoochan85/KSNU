import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# 원본 이미지 읽기 (흑백)
img = cv.imread("low_light_image.jpg", cv.IMREAD_GRAYSCALE)

# 1. Gamma Correction
gamma = 2.0   # 값은 상황에 맞게 조절 (0.5~3.0 사이 많이 사용)
invGamma = 1.0 / gamma
table = np.array([((i / 255.0) ** invGamma) * 255
                  for i in np.arange(0, 256)]).astype("uint8")
gamma_corrected = cv.LUT(img, table)

# 2. CLAHE 적용
clahe = cv.createCLAHE(clipLimit=40.0, tileGridSize=(8,8))
clahe_img = clahe.apply(img)

# 결과 시각화
titles = ["Original", "Gamma Corrected", "CLAHE"]
images = [img, gamma_corrected, clahe_img]

plt.figure(figsize=(12,4))
for i in range(3):
    plt.subplot(1,3,i+1)
    plt.imshow(images[i], cmap="gray")
    plt.title(titles[i])
    plt.axis("off")
plt.tight_layout()
plt.show()
