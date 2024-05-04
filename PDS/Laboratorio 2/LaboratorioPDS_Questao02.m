%% Questão 02 Laboratório de PDS
% Aluno: Fabrício Mady;

%% Filtro passa-baixas FIR com Janela de Blackman em cascata
Fc1 = 3000;
Fc2 = 5000;
Fs = 44100;
wc1 = (Fc1/(Fs/2))*pi;
wc2 = (Fc2/(Fs/2))*pi;
wt =(wc2 - wc1);
ordem = [ceil(11*pi/wt)];
fc = (Fc1 + Fc2)/2;
fc = fc/(Fs/2);

h2 = fir1(ordem,fc,'low',blackman(ordem+1));
sinal_filtrado = conv(h2,h2);


%%  Resposta em Frequência do Filtro

a=1;
f=0:(Fs/2) - 1;
[H,w]=freqz(h2,a,f,Fs);
mag=abs(H);

figure
DB=20*log10(mag);
plot(f,DB);grid
title('Resposta em Magnitude (dB) 1x filtrado')
ylabel('Magnitude em dB')
xlabel('Frequencia em Hz')
%-------------------------------------------------------------------------

a=1;
f=0:(Fs/2) - 1;
[H,w]=freqz(sinal_filtrado,a,f,Fs);
mag=abs(H);

figure
DB=20*log10(mag);
plot(f,DB);grid
title('Resposta em Magnitude (dB) 2x filtrado(cascata)')
ylabel('Magnitude em dB')
xlabel('Frequencia em Hz')
%-------------------------------------------------------------------------

