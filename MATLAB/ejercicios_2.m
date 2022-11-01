% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 06/Abril/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE
%% Ejercicio 1

clc;
clear;
close all;

t = 10
g = 9.81
m = 68.1
v = 40

f = @(c) (g*m)/c * (1-exp(-(c/m)*t)) - v

figure("Name",'Ejercicio 1')
fplot(f,[5 20])
title('Problema Caída Libre')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

%% Ejercicio 2

clc;
clear;
close all;

function [raiz,Iteraciones] = MetodoBiseccion(f,xi,xf,Err)
Iteraciones = 0
raiz = NaN %Not a number (no esta definido o no es un número)
xm = (xi+xf)/2
if f(xi)*f(xf)< 0 %condicional para revisar si hay 0's en el intervalo
    while abs(xf-xi) > Err
        if f(xi)*f(xf) < 0
            xf = xm
        else
            xi = xm
        end
        Iteraciones = Iteraciones + 1
        xm = (xi+xf)/2
    end
    raiz = xm
else 
    disp('Pruebe con otro intervalo :/')
end
end