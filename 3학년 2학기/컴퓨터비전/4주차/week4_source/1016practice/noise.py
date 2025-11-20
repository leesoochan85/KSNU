import cv2 as cv

img=cv.imread('source_image.png')
noisy = cv.imread('noisy_image.png')

medianB = cv.medianBlur(noisy,5)

kernel = cv.getStructuringElement(cv.MORPH_RECT,(3,3))
OpeningN=cv.morphologyEx(noisy,cv.MORPH_OPEN, kernel)
closing = cv.morphologyEx(noisy, cv.MORPH_CLOSE,kernel)

cv.imshow('Original', img)
cv.imshow('medianBlur',medianB)
cv.imshow('Opening',OpeningN)
cv.imshow('Closing',closing)

cv.waitKey()
cv.destroyAllWindows()