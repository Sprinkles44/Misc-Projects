delete(instrfind);
clear all
COM='COM3';
baud=9600;
Ard=serial(COM,'BaudRate',baud,'TimeOut',500,'DataBits',8);
fopen(Ard);
%% 
i=1;
while fscanf(Ard,'%s')~='end'
    song(i)=fscanf(Ard,'%g');
    i=i+1;
end
