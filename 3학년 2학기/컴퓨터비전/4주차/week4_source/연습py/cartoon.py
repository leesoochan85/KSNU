import cv2 as cv
import numpy as np

img=cv.imread('portrait.png')

color_img = cv.bilateralFilter(img, d=9, sigmaColor=300, sigmaSpace=300)

gray_img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
gray_img = cv.medianBlur(gray_img, 5)

edges = cv.adaptiveThreshold(gray_img, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 9, 9)

cartoon_img = cv.bitwise_and(color_img, color_img, mask=edges)

cannyEdges=cv.Canny(gray_img,50,150)
kernel=np.ones((2,2),np.uint8)
cannyEdges=cv.dilate(cannyEdges,kernel,iterations=1)

canny_color=cv.cvtColor(cannyEdges,cv.COLOR_GRAY2BGR)
cartoon_img1 = cv.addWeighted(color_img,0.8,canny_color,0.2,0)

cv.imshow('Original', img)
cv.imshow('Cartoon1 Bilateral', cartoon_img)
cv.imshow('Cartoon2 Canny',cartoon_img1)
cv.waitKey(0)
cv.destroyAllWindows()