% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 23/Mar/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE
%% Ejercicio 1

clear; 
clc;
close all

t = [-3:0.1:3]

fx = @(t) t.^2
fy = @(t) t + 1

figure("Name",'Ejercicio 1')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(t),fy(t),t)
title('Ejercicio 1')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on

%% Ejercicio 2
clear;
clc;
close all

t = [0:0.1:2*pi]

fx = @(t) 3*cos(t)
fy = @(t) 2*sin(t)

figure("Name",'Ejercicio 2')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(t),fy(t),t)
title('Ejercicio 2')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on

%% Ejercicio 3
clear;
clc;
close all

t = [-7:0.001:7]

fx = @(t) (2 + cos(1.5*t)).*cos(t)
fy = @(t) (2 + cos(1.5*t)).*sin(t)
fz = @(t) sin(1.5*t)

figure("Name",'Ejercicio 3')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(t),fy(t),fz(t))
title('Ejercicio 3')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on

%% Ejercicio 4
clear;
clc;
close all

t = [0:0.0001:2*pi];

fx = @(t) (4 + sin(20*t)).*cos(t);
fy = @(t) (4 + sin(20*t)).*sin(t);
fz = @(t) cos(20*t);

figure("Name",'Ejercicio 4')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(t),fy(t),fz(t))
title('Ejercicio 4')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on