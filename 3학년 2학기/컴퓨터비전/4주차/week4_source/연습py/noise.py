import cv2
import numpy as np
from matplotlib import pyplot as plt

# 이미지 불러오기 (흑백으로)
source = cv2.imread("source_image.png", cv2.IMREAD_GRAYSCALE)
noisy = cv2.imread("noisy_image.png", cv2.IMREAD_GRAYSCALE)

# 1. Median Filter (kernel size 5)
median = cv2.medianBlur(noisy, 5)

# 2. Opening (kernel 3x3)
kernel = np.ones((3,3), np.uint8)
opening = cv2.morphologyEx(noisy, cv2.MORPH_OPEN, kernel)

# 3. Closing (kernel 3x3)
closing = cv2.morphologyEx(noisy, cv2.MORPH_CLOSE, kernel)

# 4. Non-Local Means
nlm = cv2.fastNlMeansDenoising(noisy, None, h=10, templateWindowSize=7, searchWindowSize=21)

# 결과 출력
titles = ["Source", "Noisy Image", "Median Filter (5)", "Opening (3x3)", "Closing (3x3)", "Non-Local Means"]
images = [source, noisy, median, opening, closing, nlm]

plt.figure(figsize=(12,8))
for i in range(6):
    plt.subplot(2,3,i+1)
    plt.imshow(images[i], cmap="gray")
    plt.title(titles[i])
    plt.axis("off")
plt.tight_layout()
plt.show()
