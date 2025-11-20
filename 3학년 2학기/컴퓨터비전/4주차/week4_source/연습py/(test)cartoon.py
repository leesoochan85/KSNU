import cv2 as cv
import numpy as np

# img=cv.imread('portrait.png')
# crt=cv.stylization(img, sigma_s=100, sigma_r=0.3)
# #s=스무딩 정도( 200에 가까울수록 스무스해짐), r=엣지 살리기(0에 가까울수록 엣지많이 보존됨)

# MedianB=cv.medianBlur(crt,5)
# #정방행렬의 커널 수

# bilImg=cv.bilateralFilter(src=MedianB,d=-1,sigmaColor=50,sigmaSpace=50)
# # src = 입력영상
# # d = 필터링에 사용된 이웃픽셀의 지름, 음수 입력시sigmaSpace로 결정
# # sigmaColor = 색공간에서 필터의 표준편차(너무 크면 엣지 구분 불가)
# # sigmaSpace = 좌표공간에서 필터의 표준편차
# cv.imshow('Original', img)
# cv.imshow('Cartoon Style(Bilateral)',bilImg)

# cv.waitKey(0)
# cv.destroyAllWindows()

img=cv.imread('portrait.png')

# Apply bilateral filter for color smoothing and edge preservation
color_img = cv.bilateralFilter(img, d=9, sigmaColor=300, sigmaSpace=300)

# Convert to grayscale
gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Apply median blur to reduce noise before edge detection
gray_img = cv.medianBlur(gray_img, 5)

# Detect edges using adaptive thresholding
edges = cv.adaptiveThreshold(gray_img, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 9, 9)

# Combine color image with edges
cartoon_img = cv.bitwise_and(color_img, color_img, mask=edges)

canny = cv.Canny(edges,100,200)

cv.imshow('Original', img)
cv.imshow('canny',canny)
cv.imshow('Cartoon Image', cartoon_img)
cv.waitKey(0)
cv.destroyAllWindows()
# cv2.imwrite('cartoon_portrait.jpg', cartoon_img)