# -*- coding: utf-8 -*-
"""
Created on Mon Aug 27 21:57:38 2018

@author: Abhishek
"""
import sys
#from skimage.measure import structural_similarity as ssim (is being removed)
from skimage.measure import compare_ssim as ssim
import cv2
import numpy as np


#function to quanify the differences using ssim and MSE

def compare_MSE(p1,p2):
    
#    implementing mean squared error to find the differences
#    first convert the pictures to floats
    pic1 = p1.astype("float")
    pic2 = p2.astype("float")
    mse = np.sum((pic1 - pic2)**2)
#    mean of all the differences in pixels 
    mse /= float(pic1.shape[0] * pic1.shape[1])
    
    return mse

def compare_SSIM(p1, p2):
        
    cmp_simi = ssim(p1, p2)
    
    return cmp_simi


#load, convert to grayscale and pass to compare functions
#pic1 = cv2.imread("w0.png")
#pic1 = cv2.imread("puppy1.jpg")
pic1 = cv2.imread(sys.argv[1])
pic1 = cv2.cvtColor(pic1, cv2.COLOR_BGR2GRAY)

pic2 = cv2.imread(sys.argv[2])
#pic2 = cv2.imread("w1.png")
#pic2 = cv2.imread("puppy2.jpg")
pic2 = cv2.cvtColor(pic2, cv2.COLOR_BGR2GRAY)

print()
print("Quantifying the difference between two Images")

print("__________________________________________________________________________")
print("Similarity using MSE:")
print("0 indicates perfectly similar, >1 indicates for less similar")
mse = compare_MSE(pic1, pic2)
print("MSE:", mse)


print("__________________________________________________________________________")
print("Similarity using SSIM")
print("ranges from -1 to 1, 1 for perfecrly similar and -1 for entirely different")
simi = compare_SSIM(pic1,pic2)
print("SSIM:", simi)

print("__________________________________________________________________________")
