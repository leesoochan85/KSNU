import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

source = cv.imread("source_image.png", cv.IMREAD_GRAYSCALE)
noisy = cv.imread("noisy_image.png", cv.IMREAD_GRAYSCALE)

median = cv.medianBlur(noisy, 5)

kernel = np.ones((3,3), np.uint8)
opening = cv.morphologyEx(noisy, cv.MORPH_OPEN, kernel)

closing = cv.morphologyEx(noisy, cv.MORPH_CLOSE, kernel)

nlm = cv.fastNlMeansDenoising(noisy, None, h=10, templateWindowSize=7, searchWindowSize=21)

cv.imshow('Source',source)
cv.imshow('Noisy Image',noisy)
cv.imshow('Median Filter(5)',median)
cv.imshow('Opening(3x3)',opening)
cv.imshow('Closing(3x3)',closing)
cv.imshow('Non-Local Means',nlm)

cv.waitKey(0)
cv.destroyAllWindows()
