%% Questão 04 Laboratório de PDS
% Aluno: Fabrício Mady;

%% Filtro de Média Móvel com 12 coeficientes


Fs = 1000;
dt = 1/Fs;
t = 0:dt:1;
x = sin(2*pi*30*t) + sin(2*pi*400*t);
x1 = sin(2*pi*30*t);

figure(1)
subplot(2,1,1)
plot(t,x1,'b','LineWidth',2.2)


y = x;
hold on
plot(t,y,'k')
axis([0 .2 -3 3])
legend('Sinal s/ Ruído','Sinal c/ Ruído')

N = 12 
h2 = ones(N,1)/N;
sinal_filtrado = filter(h2,1,y);
figure(1)
subplot(2,1,2)
plot(t,sinal_filtrado,'r')
axis([0 .2 -3 3])
legend('Sinal Filtrado')

a=1;
f=0:(Fs/2) - 1;
[H,w]=freqz(h2,a,f,Fs);
mag=abs(H);

figure
plot(f,mag);grid
title('Resposta do Filtro')
ylabel('Magnitude')
xlabel('Frequência(Hz)')

figure
DB=20*log10(mag);
plot(f,DB);grid
title('Resposta do Filtro em dB')
ylabel('Magnitude (dB)')
xlabel('Frequência (Hz)')

