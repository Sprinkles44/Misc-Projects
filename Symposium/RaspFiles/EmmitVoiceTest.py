import numpy as np
import scipy as sci
from scipy import stats
import math
import pyaudio # sudo apt-get python3-pyaudio

import simpleaudio as sa

PyAudio = pyaudio.PyAudio
sampRate = 48000  # Voice sample rate
print("sampRate:\t\t%d" % sampRate)
fundFreq = 211  # Fundamental frequency from human voice sample
# domFreq = 3000  # Dominant frequency from human voice sample

sVal = []
with open('sensorLogTestValues3.txt','r') as file:
	for line in file:
		sVal.append(file.readline())

# **********************************************************************************************************************
# print("sVal:  %s\n" % sVal)
# **************************************************************************
# N = 150  # number of data points
# t = np.linspace(0,17,N)
# testVals = 400*np.log10(2*t+10) + np.random.randn(N)  # create artificial data with noise
# for num in testVals:  # Eliminating duplicate values
# 	if num not in sVal:
# 		sVal.append(int(num))
# **********************************************************************************************************************

sVal = [int(i) for i in sVal]

# **********************************************************************************************************************
# sVal = np.array(sVal)
# **********************************************************************************************************************
# with open('sensorLogTestValues3.txt','w+') as file:
# 	string = '\n'.join([str(i) for i in sVal])
# 	file.write(string)
# print(sVal)
# **********************************************************************************************************************
# X = np.linspace(0,len(sVal),1)
# sVal_length = len(sVal)
# X = np.arange(sVal_length)
# X_length = len(X)
# print("sVal length:  %d\nX length:  %d\n" % (sVal_length,X_length))
# **********************************************************************************************************************

E_freq = int(np.mean(sVal))  # Avg of captured sensor values will become the frequency of Emmit's voice
print("E_freq:\t\t\t%d" % E_freq)
# avg_freq = (E_freq+fundFreq)/2  # Initial voice frequency
trans_freq = (fundFreq+E_freq)/2  # Transitioning voice frequency
slope, intercept, r_value, p_value, std_err = stats.linregress(np.arange(len(sVal)),sVal)  # Determines the rate of change of the frequency
print("slope:\t\t\t%.2f\nintercept:\t\t%.2f\nr_value:\t\t%.2f\np_value:\t\t%.2f\nstd_err:\t\t%.2f" % (slope,intercept,r_value,p_value,std_err))
vlength = .75 + (1/slope) # Length of the output voice in seconds
print("vlength:\t\t%.2f" % vlength)
numberofFrames = int(sampRate * vlength)
print("numberofFrames:\t%d" % numberofFrames)
restofFrames = numberofFrames % sampRate
print("restofFrames:\t%d" % restofFrames)
# **********************************************************************************************************************
# blockOFrames = int(numberofFrames/]3)
# **********************************************************************************************************************

x = np.linspace(0,vlength, int(vlength * sampRate),False)
voice_data = np.sin((x/(sampRate/trans_freq)/np.pi)*np.sin(x/E_freq)*np.sin(x/sampRate))
voice = np.hstack(voice_data)
voice *= 32767 / np.max(np.abs(voice_data))
voice = voice.astype(np.int16)

play_obj = sa.play_buffer(voice,1,1,sampRate)

play_obj.wait_done()




# **********************************************************************************************************************
# m = (E_freq - fundFreq)/(2*vlength)  # m = (ending_freq - beginning_freq)/(2*duration)
# print("m:\t\t\t%.2f" % m)
# **********************************************************************************************************************
# voicedata = ''
# rx = 1+math.fabs((trans_freq-avg_freq)/avg_freq)
# for x in range(int(numberofFrames/5)):
# 	voicedata = voicedata + chr(int(math.sin(x/((sampRate/3000)/math.pi)*.5)*127+128))
#
# for x in range(int(numberofFrames/4)):
# 	voicedata = voicedata + chr(int(math.sin(x/((sampRate/E_freq)/math.pi))*127+128))
#
# for x in range(int(numberofFrames/3)):
# 	voicedata = voicedata + chr(int(math.sin(x/((sampRate/avg_freq)/math.pi))*127+128))
# **********************************************************************************************************************
# modulation = 20  # Hard coded voice modulation
# **********************************************************************************************************************
# **********************************************************************************************************************
# voicedata = ''
# for x in range(numberofFrames + restofFrames):
# 	voicedata = voicedata + chr(int(math.sin((x/(sampRate/trans_freq)/math.pi)*math.sin(x/E_freq)*math.sin(x/sampRate+slope))*127+128))
# **********************************************************************************************************************
# **********************************************************************************************************************
#
# voicedata = []
# for x in range(numberofFrames + restofFrames):
# 	voicedata.append(int(math.sin((x/(sampRate/trans_freq)/math.pi)*math.sin(x/E_freq)*math.sin(x/sampRate+slope))*127+128))
#
# # voicedata = np.array(voicedata)
# voicedata = [int(i) for i in voicedata]

# **********************************************************************************************************************
# print("voicedata_max:\t%d" % np.amax(voicedata))
# norm_coef = math.fabs(np.amin(voicedata)/np.amax(voicedata))
# norm_voice = []
# for i in voicedata:
# 	norm_voice.append(norm_coef*i)
#
# voice = ''
# for i in norm_voice:
# 	voice = voice + chr(int(i))
# **********************************************************************************************************************
# for x in range(restofFrames):
# 	voicedata = voicedata + chr(int(math.sin((x/(sampRate/E_freq)/math.pi)*math.sin(fundFreq*x))*127+128))
# **********************************************************************************************************************
# x_range = np.linspace(0, slope*numberofFrames, numberofFrames)
# x_range = [int(i) for i in x_range]
# voicedata = ''
# for x in x_range:
# 	voicedata = voicedata + chr(int(math.sin((x/byterate)**2)))
# **********************************************************************************************************************
# voicedata = ''
# for x in range(numberofFrames):
# 	voicedata = voicedata + chr(int(math.sin)
# **********************************************************************************************************************
# for i in range(restofFrames):
# 	voicedata = voicedata + chr(123)
# **********************************************************************************************************************
# with p.open("Emmit'sActualVoice.wav",'w+') as wavfile:
# 	wavfile.write(voicedata)
# **********************************************************************************************************************
# p = PyAudio()
# stream = p.open(format = p.get_format_from_width(1),
# 				channels = 1,
# 				rate = sampRate,
# 				output = True)
#
# stream.write(voicedata)
# stream.stop_stream()
# stream.close()
# p.terminate()
# **********************************************************************************************************************