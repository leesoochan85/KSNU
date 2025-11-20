import cv2 as cv

img=cv.imread('portrait.png')

smooth=cv.bilateralFilter(img,9,300,300)
gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
gray_blur=cv.medianBlur(gray,5)
edge_thresh=cv.adaptiveThreshold(gray_blur,255,cv.ADAPTIVE_THRESH_MEAN_C,cv.THRESH_BINARY,9,9)
cartoon = cv.bitwise_and(smooth,smooth, mask=edge_thresh)

canny_edge=cv.Canny(gray_blur,80,150)
# color_canny=cv.cvtColor(canny_edge,cv.COLOR_GRAY2BGR)
edge_inv=cv.bitwise_not(canny_edge)
cartoon2=cv.bitwise_and(smooth,smooth,mask=edge_inv)

cv.imshow('Original',img)
cv.imshow('cartoon(bilateral)',cartoon)
cv.imshow('cannyEdge',cartoon2)
cv.waitKey()
cv.destroyAllWindows()