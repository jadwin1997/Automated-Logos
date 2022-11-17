#Code Description:
#Program takes a user-input image and separates the colors into newly saved image files.
#The code cannot detect and save white parts of the image as a numPy array (potential solution: for completely white images, invert the color before uploading to GUI)
#Code also has issues picking up thin lines (look into fine-tuning)

import numpy as np
import numpy as gfg
import cv2


import os 
assert os.path.exists("Image Processing")

#Opening the source image
PepsiLogo = "PepsiLogo.png"
ColorWheel = "ColorWheel.jpg"
#WhiteBlack = 'WhiteCircleBlackBg.png'
MSULogo = "MSULogo.png"
MsStateLogo = "MsStateLogo.png"
#FootballField = "FootballField.jpg"
filename = PepsiLogo
img=cv2.imread(filename, cv2.IMREAD_UNCHANGED)
img=cv2.resize(img, (0,0), fx=.25, fy=.25)


#convert color from RGB to HSV
img_hsv=cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

#HSV RANGES FOR EACH COLOR:
count=1
for i in range(1,10): #runs through each color option (count is incremented at end of loop)
    if count==1:
        #Red
        lower= np.array([170,70,0], np.uint8) #may encounter some issues because red wraps around the HSV spectrum, so lower is both [0, 70, 50] and [170, 70,50]
        upper= np.array([180,255,255], np.uint8)                                                                       #upper is both [10, 255, 255] and [180, 70, 50]
    elif count==2:
        #Orange
        lower= np.array([10,100,0], np.uint8)  
        upper= np.array([25,255,255], np.uint8)
    elif count==3:
        #Yellow
        lower= np.array([25,100,0], np.uint8)  
        upper= np.array([35,255,255], np.uint8)
    elif count==4:
        #Green
        lower= np.array([35,100,0], np.uint8)   
        upper= np.array([80,255,255], np.uint8)
    elif count==5:
        #Blue
        lower= np.array([80,150,0], np.uint8)     
        upper= np.array([110,255,255], np.uint8)
    elif count==6:
        #Purple
        lower= np.array([125,100,0], np.uint8)      #may need to adjust (sometimes picks up blue as well)
        upper= np.array([150,255,255], np.uint8)
    elif count==7:
        #Pink/magenta
        lower= np.array([150,100,0], np.uint8)  
        upper= np.array([165,255,255], np.uint8)
    elif count==8:
        #Black
        lower= np.array([0,0,0], np.uint8)            
        upper= np.array([0,0,0], np.uint8)
    #elif count==9:
        #White
        #lower= np.array([0,0,0], np.uint8) #Same HSV range as black because the black output is inverted further down to detect white sections           
        #upper= np.array([0,0,0], np.uint8)



    mask=cv2.inRange(img_hsv, lower, upper)

    #Getting the foreground
    foreground = cv2.bitwise_or(img, img, mask=mask)  #shows isolated color with black background

    #Getting the background
    mask = cv2.bitwise_not(mask)
    background = np.full(img.shape, 255, dtype=np.uint8) #creates new variable "background" with same size as original img and filled with white
    bk= cv2.bitwise_or(background, background, mask=mask) 

    #combining the foreground and background to create an output that has isolated color
    output= cv2.bitwise_or(foreground, bk)
    
    #Inverting the color of the black output, so there is a numPy array for the white sections
    #This may cause an issue for images that have a black background; some sections that are not black may be painted over with white (just be aware of that)
    #if count==9:
        #output=cv2.bitwise_not(output)


    #Display image, mask, and altered images
    cv2.imshow("Original Image", img)
    #cv2.imshow("Mask", mask)
    if count==1:
        if np.mean(output) != 255: #checks to see if the output image has any color. If it does, then the image should be saved.
            cv2.imshow("Red", output)
            cv2.imwrite('Red'+filename, output) #should save a new image with just the red portions named "Red"+filename
    elif count==2:
        if np.mean(output) != 255:
            cv2.imshow("Orange", output)
            cv2.imwrite('Orange'+filename, output)
    elif count==3:
        if np.mean(output) != 255:
            cv2.imshow("Yellow", output)
            cv2.imwrite('Yellow'+filename, output)
    elif count==4:
        if np.mean(output) != 255:
            cv2.imshow("Green", output)
            cv2.imwrite('Green'+filename, output)
    elif count==5:
        if np.mean(output) != 255:
            cv2.imshow("Blue", output)
            cv2.imwrite('Blue'+filename, output)

    elif count==6:
        if np.mean(output) != 255:
            cv2.imshow("Purple", output)
            cv2.imwrite('Purple'+filename, output)
    elif count==7:
        if np.mean(output) != 255:
            cv2.imshow("Pink/Magenta", output)
            cv2.imwrite('Pink'+filename, output)
    elif count==8:
        if np.mean(output) != 255:
            cv2.imshow("Black", output)
            cv2.imwrite('Black'+ filename, output)  
    #elif count==9:
        #if np.mean(output) != 255:
            #cv2.imshow("White Section (Inverted)", output)
            #cv2.imwrite("White"+filename, output)
    count=count+1

#press any key to end program
cv2.waitKey(0)
cv2.destroyAllWindows()

#To-Do:
# - figure out HSV ranges for each color /DONE
# - Layer the mask onto the original image to isolate color /DONE
# - Save new image with isolated color /DONE
# - figure out issue with saving pngs with transparent backgrounds 
# - figure out how to save new images for only the colors present (ex. a logo with R, Black, Yellow should not save images for blue, purple, green) /DONE
# - Set up a way for user-uploaded files to be read at the beginning of the code