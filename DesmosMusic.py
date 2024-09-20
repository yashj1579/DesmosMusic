import pyautogui as py
import time
import cv2
import keyboard as kb
import os

#open chrome
py.keyDown("command")
py.press("space")
py.keyUp("command")
time.sleep(1)
py.write("chrome")
py.press("enter")
time.sleep(1)

py.keyDown("command")
py.press("t")
py.keyUp("command")

#open website
py.write("https://www.desmos.com/calculator")
time.sleep(1)
py.press("enter")
time.sleep(1)

#input basic function
py.write("f(x)=440*2^(x/12)")
py.press("enter")

duration = 300 #change this depending on the number of lines you have
interval = 0.005 #change this depending on the interval you have
#create slider. Turn this on to run song. Change speed as desired.
py.write("a=1")
py.press("enter")
py.press("up")
py.press("tab")
py.press("tab")
py.write("0")
py.press("tab")
py.write(str(duration))
py.press("tab")
py.write(str(interval))
py.press("enter")
time.sleep(1)
py.press("enter")

#IMPORTANT: CHANGE DIRECTORY TO THE FOLDER THAT CONTAINS .txt file.
os.chdir("/Users/yashjain/Desktop/Programming/CPPLabs/usacoPractice/cmake-build-debug")
f = open("desmoss.txt","r")

#write each line into desmos
count = 0
for line in f:
    kb.write(line[0:-1])
    py.press("enter")
    if count == 20:
        break

