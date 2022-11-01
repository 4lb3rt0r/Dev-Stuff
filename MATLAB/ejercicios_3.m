% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 13/Abril/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE

%% Ejercicio 1

clc;
clear;
close all;

f = @(x) sin(x) + x
f2 = @(x) x

subplot(2,1,1)
fplot(f)
hold on
fplot(f2)
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(f)
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,0)
fprintf('La raíz de la función es: %0.6\n', root)

%% Ejercicio 2

clc;
clear;
close all;

f = @(x) (2*(x^2))-5
f2 = @(x) x

subplot(2,1,1)
fplot(f,[-2,2])
hold on
fplot(f2,[-2,2])
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(f,[-2,2])
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,0)
fprintf('La raíz de la función es: %0.6\n',root)

%% Ejercicio 3

clc;
clear;
close all;

f = @(x) cos(x) - x
f2 = @(x) x

subplot(2,1,1)
fplot(f)
hold on
fplot(f2)
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(f)
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,0)
fprintf('La raíz de la función es: %0.6\n', root)

%% Ejercicio 4

clc;
clear;
close all;

f = @(x) exp(-x)
f2 = @(x) x

subplot(2,1,1)
fplot(f)
hold on
fplot(f2)
title('Puntos Fijos')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

subplot(2,1,2)
fplot(f)
hold on
%fplot(f2)
title('Grafica Original')
xlabel('Ejes de las x')
ylabel('Ejes de las y')
hline = refline(0,0)
hline.Color = 'r'
grid on

root = fzero(f,0)
fprintf('La raíz de la función es: %0.6\n',root)

%% Ejercicio 5 - Newton-Raphson

syms f(x)
f(x) = exp(-x) - x
fdx = diff(f(x))

[xi,Iteraciones] = NewtonR(f,fdx,0,0.001)
%% Ejercicio 5.2 - Newton-Raphson

function [xi,Iteraciones] = NewtonR(f,fdx,xi,error)
Iteraciones = 0
    while abs(subs(f,xi) > error)
        xi = xi - subs(f,xi)/subs(fdx,xi)
        Iteraciones = Iteraciones + 1
    end
    r = subs(f,xi)
    xi = double(xi)
end
