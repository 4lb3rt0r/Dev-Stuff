% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 17/Abril/21

% ACTIVIDAD 3 - METODO DE NEWTON-RAPHSON 

%% Ejercicio 1

clc;
clear;
close all;

x = [0 15]
f =@(x) (-x.^2)/10 +3

y1 = @(x) 30/x
y2 = @(x) x

subplot(2,1,1)
fplot(y1,[-15,15])
hold on
fplot(y2,[-15,15])
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(y1,[-15,15])
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,x)
fprintf('La raíz de la función con fzero es:')
disp(root)

%% Ejercicio 1.2
syms f(x)
f(x) = (-x.^2)/10 +3
fdx = diff(f(x))

[xi,Iteraciones] = NewtonR(f,fdx,5.5,0.001)

%% Ejercicio 2

clc;
clear;
close all;

x = [0 5]
f =@(x) cos(x) - x.^3

y1 = @(x) (cos(x)).^(1/3)
y2 = @(x) x

subplot(2,1,1)
fplot(y1,[-3,4])
hold on
fplot(y2,[-3,4])
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(y1,[-3,4])
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,x)
fprintf('La raíz de la función con fzero es:')
disp(root)

%% Ejercicio 2.2

syms f(x)
f(x) = cos(x) - x^3
fdx = diff(f(x))

[xi,Iteraciones] = NewtonR(f,fdx,0.863921,0.001)

%% Ejercicio 3

clc;
clear;
close all;

x = [-6 6]
f =@(x) x.^3 + x + 16

y1 = @(x) -x.^3 - 16
y2 = @(x) x

subplot(2,1,1)
fplot(y1,[-6,6])
hold on
fplot(y2,[-6,6])
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(y1,[-6,6])
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,x)
fprintf('La raíz de la función con fzero es:')
disp(root)

%% Ejercicio 3.2

syms f(x)
f(x) = x^3 + x + 16
fdx = diff(f(x))

[xi,Iteraciones] = NewtonR(f,fdx,-2.5198,0.001)

%% Ejercicio 4

clc;
clear;
close all;

x = [0 2]
f =@(x) x.^4 + 2.*x - 1

y1 = @(x) (-x.^4 + 1)/2
y2 = @(x) x

subplot(2,1,1)
fplot(y1,[-2,4])
hold on
fplot(y2,[-2,4])
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(y1,[-2,4])
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,x)
fprintf('La raíz de la función con fzero es:')
disp(root)

%% Ejercicio 4.2

syms f(x)
f(x) = x^4 + 2*x - 1
fdx = diff(f(x))

[xi,Iteraciones] = NewtonR(f,fdx,1,0.001)