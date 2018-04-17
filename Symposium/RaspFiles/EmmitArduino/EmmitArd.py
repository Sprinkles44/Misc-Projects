#!/usr/bin/env python3

import RPi.GPIO as gpio
import re
import serial
import time

time.sleep(3)
ard = serial.Serial('/dev/ttyAMA0',115200)
time.sleep(.2)
ard.flush()

try:
        while True :
                p = ard.readline()
                aV = p.decode('ASCII')
                # print (aV)
                # results = re.findall(r"[-+]?\d*\.\d+|\d+",aV)
                aV = int(aV)
                print(aV)
                # activeVals = []
                # c0 = 0
                # if aV == 0 :
                #         c = c + 1
                # else:
                #         activeVals.append(aV)

except ValueError:
        print ("No Input Data")

