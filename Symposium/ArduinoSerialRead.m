seriallist
COM=input('Enter the name of your device port. \n');
baud=input('Input the baudrate of your device: ');
Ard=serial(COM,'BaudRate',baud);
fopen(Ard);
song= fscanf(Ard,'%g');
fileID=fopen('MySong.txt','w');
fprintf(fileID,'%g\n',song);
