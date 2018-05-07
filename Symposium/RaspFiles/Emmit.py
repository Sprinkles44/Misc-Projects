#!/usr/bin/python3

import RPi.GPIO as GPIO
import PCF8591 as ADC  # "import smbus"  is inside the PCF8591.py file
import time
import numpy as np
from scipy import stats
import math
import pyaudio # sudo apt-get python3-pyaudio


PyAudio = pyaudio.PyAudio
byterate = 16000
fundFreq = 323  # Fundamental frequency from human voice sample
domFreq = 3000  # Dominant frequency from human voice sample


def setup():
	ADC.setup(0x48)
	GPIO.setmode(GPIO.BCM)


def ambientLight(svty):  # Input sensitivity
	test = 50
	ambVal = []
	for i in range(0, test):
		ambVal.append(ADC.read(0))
	ambVal = [int(i) for i in ambVal]
	ambAvg = np.mean(ambVal)
	ambUpper = ambAvg + svty
	ambLower = ambAvg - svty
	return ambLower, ambUpper  # Outputs the ambient light's lower and upper bounds


def loop(ambLower,ambUpper):  # loop(lower_ambient_light_value,upper_ambient_light_value)
	vs = 150  # Voice response sensitivity
	sVal = []
	c0 = 0
	while True:
		s = ADC.read(0)
		for i in range(0,vs):  # Refreshing scenery every "vs = 150" captured values
			if ambUpper <= s <= ambLower:
				sVal.append(s)
			else:
				c0 = c0 + 1
		if sVal:  # Voice response
			sVal = [int(i) for i in sVal]
			s_avg = np.mean(sVal)  # Avg of captured sensor values will become the dominant frequency
			slope,intercept,r_value,p_value,std_err = stats.linregress(sVal,np.linspace(0,len(sVal)))  # Determines the rate of change of the frequency
			vlength = 1 + r_value  # Length of the output voice in seconds
			numberofFrames = int(byterate * vlength)
			for x in range(numberofFrames):
				voicedata = fundFreq + int(math.sin(slope*x/((byterate/s_avg)/math.pi)))
			p = PyAudio()
			stream = p.open(format = p.get_format_from_width(vlength),
							channels = 1,
							rate = byterate,
							output = True)
			stream.write(voicedata)
			stream.stop_stream()
			stream.close()
			p.terminate()


def destroy():
	ADC.write(0)


if __name__ == "__main__":
	try:
		setup()
		aLow, aUp = ambientLight(15)
		loop(aLow,aUp)
	except KeyboardInterrupt:
		destroy()
