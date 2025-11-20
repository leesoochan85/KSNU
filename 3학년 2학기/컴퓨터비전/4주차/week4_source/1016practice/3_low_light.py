import cv2 as cv 
import numpy as np

img=cv.imread('low_light_image.jpg')
gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)

img_normalized=gray.astype(np.float32)/255.0

gamma_value=2.0
gamma_corrected_img = np.power(img_normalized,1.0/gamma_value)

gamma_corrected_img = np.clip(gamma_corrected_img*255,0,255).astype(np.uint8)

clahe=cv.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
gamma_clahe= clahe.apply(gamma_corrected_img)

cv.imshow('Original',gray)
cv.imshow('Gamma',gamma_corrected_img)
cv.imshow('Clahe',gamma_clahe)
cv.waitKey()
cv.destroyAllWindows()