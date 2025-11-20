import cv2 as cv
import numpy as np

img = cv.imread("low_light_image.jpg", cv.IMREAD_GRAYSCALE)

gamma = 2.0   
invGamma = 1.0 / gamma
table = np.array([((i / 255.0) ** invGamma) * 255
                  for i in np.arange(0, 256)]).astype("uint8")
gamma_corrected = cv.LUT(img, table)

clahe = cv.createCLAHE(clipLimit=40.0, tileGridSize=(8,8))
clahe_img = clahe.apply(img)

cv.imshow('Original',img)
cv.imshow('Gamma Corrected',gamma_corrected)
cv.imshow('CLAHE',clahe_img)

cv.waitKey()
cv.destroyAllWindows()