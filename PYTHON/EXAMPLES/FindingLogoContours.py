import numpy as np
import cv2

#Opening the src image
img=cv2.imread('FILENAME', cv2.IMREAD_UNCHANGED)
img=cv2.resize(img, (0,0), fx=0.2, fy=0.2)

#converting image to grayscale
img_gray=cv2.cvtColor(img, cv2. COLOR_BGR2GRAY)

#Set threshold and convert image to black and white
thresh, img_edges = cv2.threshold(img_gray, 50, 255, cv2.THRESH_BINARY) #Adjust 2nd argument to raise/lower threshold for lighter colors

#Create canvas
canvas = np.zeros(img.shape, np.uint8)
canvas.fill(255) #fills canvas with white

#Find Contours
contours_mask, hierarchy = cv2.findContours(img_edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

#draw contours on canvas
for contour in range(len(contours_mask)):
    cv2.drawContours(canvas, contours_mask, contour, (0,0,0), 3)

#Display original image, grayscale image, 

#press any key to end program
cv2.waitKey(0)
cv2.destroyAllWindows()