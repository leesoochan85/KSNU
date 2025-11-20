import cv2 as cv

img = cv.imread('portrait.png')                 # 같은 폴더에 이미지

# 1) 색 면을 부드럽게: 모서리 보존 스무딩
smooth = cv.bilateralFilter(img, d=9, sigmaColor=300, sigmaSpace=300)

# 2A) 선(엣지) - 적응형 임계값 방식 (카툰1)
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
gray_blur = cv.medianBlur(gray, 5)
edges_thresh = cv.adaptiveThreshold(gray_blur, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 9, 9)
cartoon1 = cv.bitwise_and(smooth, smooth, mask=edges_thresh)

# 2B) 선(엣지) - Canny 방식 (카툰2)
edges_canny = cv.Canny(gray_blur, 100, 200)
edges_canny_bgr = cv.cvtColor(edges_canny, cv.COLOR_GRAY2BGR)
cartoon2 = cv.subtract(smooth, edges_canny_bgr)

# 필요하면 미리보기
cv.imshow('Original',img)
cv.imshow('cartoon1', cartoon1) 
cv.imshow('cartoon2', cartoon2) 
cv.waitKey()
cv.destroyAllWindows()
