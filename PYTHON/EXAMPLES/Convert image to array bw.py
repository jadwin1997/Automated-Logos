import cv2
import numpy as np
from PIL import Image, ImageColor
field_width = 360
field_height = 160
#mapping function
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

im = cv2.imread("testing3.jpg")
im = cv2.resize(im, (field_width*10,field_height*10))

#Set upper and lower bounds for HSV mask to find contours to track. Refer to HSV color chart to get correct color (THIS IS NOT RGB)
lower = [0,0,0] #[25,50,0] lower bound for yellow
upper = [255, 255, 150]#[40,255,255] upper bound for yellow

# create NumPy arrays from the color boundaries given
lower = np.array(lower, dtype="uint8")
upper = np.array(upper, dtype="uint8")
mask = cv2.inRange(im,lower,upper)
output = cv2.bitwise_and(im,im,mask=mask)


img = Image.fromarray(mask)
contours, hierarchy = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
img.save("bw.png")
output = cv2.drawContours(im, contours, -1, (0, 0, 255), 3)
# Showing the output
cv2.imshow("im",im)
cv2.waitKey(0)

    
