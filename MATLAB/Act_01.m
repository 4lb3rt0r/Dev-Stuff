% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 23/Mar/21                Tarea: Actividad 01 - Graficación

%% Ejercicio 1
clear;
clc; 
close all;

t = [1:0.1:1000]

fx = @(t) t.^2 + 2.*t
fy = @(t) t.^10 + t.^3 + t.^2 + t

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
close all;

t = [1:0.1:600]

fx = @(t) t.^5 - 10.*t
fy = @(t) 2.*t - 4

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
close all;

a = 2
b = 0.25
w = 2
t = [0:0.001:12*pi]

fx = @(a,w,t) a.*cos(w.*t)
fy = @(a,w,t) a.*sin(w.*t)
fz = @(b,t) b.*t

figure("Name",'Ejercicio 3')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(a,w,t),fy(a,w,t),fz(b,t))
title('Ejercicio 3')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on

%% Ejercicio 4
clear;
clc;
close all;

a = 1
b = 1
u = [0:0.001:2*pi]
t = [0:0.001:2*pi]

fx = @(a,u,t) a.*cos(t).*cos(u)
fy = @(b,u,t) b.*cos(t).*sin(u)
fz = @(t) cos(t).^3

figure("Name",'Ejercicio 4')
%plot(fx(t),fy(t))
%plot3(fx(t),fy(t),t)
%comet(fx(t),fy(t))
comet3(fx(a,u,t),fy(a,u,t),fz(t))
title('Ejercicio 4')
xlabel('x')
ylabel('y')
zlabel('z')
legend('Trayectoria')
grid on

%% Ejercicio 5
hold on
rectangle('Position',[1 1 3 3.5],'Curvature',[1,1],'FaceColor','r','EdgeColor',[1 0 1])
rectangle('Position',[4 4 3 3.5],'Curvature',[1,1],'FaceColor','b','EdgeColor',[0 1 1])
rectangle('Position',[7 7 3 3.5],'Curvature',[1,1],'FaceColor','y','EdgeColor',[0 1 0])
rectangle('Position',[10 10 3 3.5],'Curvature',[1,1],'FaceColor','g','EdgeColor',[1 1 0])
rectangle('Position',[13 13 3 3.5],'Curvature',[1,1],'FaceColor','c','EdgeColor',[0 0 1])
rectangle('Position',[16 16 3 3.5],'Curvature',[1,1],'FaceColor','m','EdgeColor',[1 0 0])
axis([1 7 1 7])

%% Ejercicio 6
[x,y] = meshgrid(0:0.2:2,0:0.2:2)
u = cos(x).*y
v = sin(x).*y
figure
quiver(x,y,u,v)
%% Ejercicio 6.2
[x,y] = meshgrid(0:-0.2:-2,0:-0.2:-2)
u = cos(x).*y
v = sin(x).*y
figure
quiver(x,y,u,v)
%% Ejercicio 6.3
[x,y] = meshgrid(0:0.2:2,0:0.2:2)
u = sin(x).*y
v = cos(x).*y
figure
quiver(x,y,u,v)
%% Ejercicio 6.4
[x,y] = meshgrid(0:0.2:2,0:0.2:2)
u = cos(-x).*y
v = sin(-x).*y
figure
quiver(x,y,u,v)

%% Ejercicio 6.5
[x,y] = meshgrid(0:0.2:2,0:0.2:2)
u = cos(x).*-2.*y
v = sin(-2.*x).*y
figure
quiver(x,y,u,v)