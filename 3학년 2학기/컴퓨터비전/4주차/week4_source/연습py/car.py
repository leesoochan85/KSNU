import cv2 as cv
import numpy as np

# 이미지 불러오기
img = cv.imread('portrait.png')

color_img = cv.bilateralFilter(img, d=9, sigmaColor=300, sigmaSpace=300)  # 색 부드럽게
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
gray_img = cv.medianBlur(gray_img, 5)  # 잡음 제거
edges = cv.adaptiveThreshold(gray_img, 255,
                             cv.ADAPTIVE_THRESH_MEAN_C,
                             cv.THRESH_BINARY, 9, 9)  # 윤곽선
cartoon1 = cv.bitwise_and(color_img, color_img, mask=edges)

cannyEdges = cv.Canny(gray_img, 50, 150)
edges_inv = cv.bitwise_not(cannyEdges)
cartoon2 = cv.bitwise_and(color_img, color_img, mask=edges_inv)

cv.imshow('Original', img)
cv.imshow('Cartoon Style 1 (Bilateral + Adaptive Threshold)', cartoon1)
cv.imshow('Cartoon Style 2 (Bilateral + Canny)', cartoon2)

cv.waitKey(0)
cv.destroyAllWindows()
