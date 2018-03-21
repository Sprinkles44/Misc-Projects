delete(instrfind);
close all
clear all
seriallist
% COM=input('Enter the name of your device port:\n','s');
COM='COM3';
% baud=input('Input the baudrate of your device:\n');
baud=9600;
Ard= serial(COM,'BaudRate',baud,'TimeOut',100,'DataBits',8);
fopen(Ard);

%% Retreive live info from Arduino
i=1;
dur=500;
while i<=dur
    song(i)=fscanf(Ard,'%d');
    i=i+1;
end

mx=max(song);
mn=min(song);
for j=1:dur
    soundsc(song(j),[mn,mx]);
end
i=1;

fclose(Ard);