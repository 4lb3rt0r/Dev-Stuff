% F1013B.4 - Modelación Computacional de Sistemas Eletromagnéticos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 23/Mayo/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE

%% EJEMPLO ARCHIVO
clear;
clc;
close all;

m = [7 1 10 5 4 3 13 10 2;2 9 2 5 7 11 2 5 14]
csvwrite('PuntosXYejemplo.csv',m)

%% EJEMPLO EJERCICIO
clear;
clc;
close all;

%Matriz = readmatrix('PuntosXYejemplo.csv')
Matriz = csvread('PuntosXYejemplo.csv')
x = Matriz(1,:)
y = Matriz(2,:)
%Procedemos a llamar a la función minimosC.m
[m,b] = minimosC(x,y)
%Scatter plot
figure("Name",'Ejercicio de Ejemplo')
plot(x,y,'pb','MarkerSize',14)
hold on
%Resultado de la Regresión
%f = @(x) m*x + b   **método alterno
%recta = f(x)       **método alterno
recta = m.*x + b
plot(x,recta)
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title(['m = ' num2str(m) ' b = ' num2str(b)])
legend('Datos','Recta Aproximada')
grid on
%% Ejercicio 1
clear;
clc;
close all;

%Matriz = readmatrix('PuntosXYejemplo.csv')
Matriz = csvread('PuntosXY.csv')
x = Matriz(1,:)
y = Matriz(2,:)
%Procedemos a llamar a la función minimosC.m
[m,b] = minimosC(x,y)
%Scatter plot
figure("Name",'Ejercicio 1')
plot(x,y,'ob','MarkerSize',4)
hold on
%Resultado de la Regresión
%f = @(x) m*x + b   **método alterno
%recta = f(x)       **método alterno
recta = m.*x + b
plot(x,recta)
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title(['m = ' num2str(m) ' b = ' num2str(b)])
legend('Datos','Recta Aproximada','Location','northwest')
grid on

%% Ejercicio 2
clear;
clc;
close all;

%Matriz = readmatrix('PuntosXYejemplo.csv')
Matriz = csvread('PuntosXY3.csv')
x = Matriz(1,:)
y = Matriz(2,:)
%Procedemos a llamar a la función minimosC.m
[m,b] = minimosC(x,y)
%Scatter plot
figure("Name",'Ejercicio 2')
plot(x,y,'ob','MarkerSize',4)
hold on
%Resultado de la Regresión
%f = @(x) m*x + b   **método alterno
%recta = f(x)       **método alterno
recta = m.*x + b
plot(x,recta)
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title(['m = ' num2str(m) ' b = ' num2str(b)])
legend('Datos','Recta Aproximada','Location','northwest')
grid on

%% Ejercicio 3
clear;
clc;
close all;

%Matriz = readmatrix('PuntosXYejemplo.csv')
Matriz = csvread('PuntosXY7.csv')
x = Matriz(1,:)
y = Matriz(2,:)
%Procedemos a llamar a la función minimosC.m
[m,b] = minimosC(x,y)
%Scatter plot
figure("Name",'Ejercicio 3')
plot(x,y,'h','MarkerSize',4)
hold on
%Resultado de la Regresión
%f = @(x) m*x + b   **método alterno
%recta = f(x)       **método alterno
recta = m.*x + b
plot(x,recta)
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title(['m = ' num2str(m) ' b = ' num2str(b)])
legend('Datos','Recta Aproximada','Location','northwest')
grid on

%% Ejercicio 4
clear;
clc;
close all;

%Matriz = readmatrix('PuntosXYejemplo.csv')
Matriz = csvread('PuntosXY10.csv')
x = Matriz(1,:)
y = Matriz(2,:)
%Procedemos a llamar a la función minimosC.m
[m,b] = minimosC(x,y)
%Scatter plot
figure("Name",'Ejercicio 4')
plot(x,y,'*','MarkerSize',4)
hold on
%Resultado de la Regresión
%f = @(x) m*x + b   **método alterno
%recta = f(x)       **método alterno
recta = m.*x + b
plot(x,recta)
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title(['m = ' num2str(m) ' b = ' num2str(b)])
legend('Datos','Recta Aproximada','Location','northeast')
grid on