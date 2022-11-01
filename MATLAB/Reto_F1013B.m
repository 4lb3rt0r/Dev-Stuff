clc; clear; close all

%Inicializamos Variables y Constantes
ke = 8.9876 * 10 ^9;
Q1 = 10; % Input
Q2 = -10; % Input

Q1_d = 1; % Diametro
Q2_d = 1; % Diametro

Q1x = 0; % Posicion Input
Q1y = 0; % Posicion Input
Q2x = 8; % Posicion Input
Q2y = 0; % Posicion Input

R = Q2x - Q1x;

figure("name","Quiver")
x = linspace(-5,15,20);
y = linspace(-5,15,20);
%[x,y] = meshgrid(-5:1:15, -5:1:15);
[x,y] = meshgrid(x, y);

r1x = x - Q1x; % elemento î del vector de Q1 hasta el punto
r1y = y - Q1y; % elemento j del vector de Q1 hasta el punto
r2x = x - Q2x; % elemento î del vector de Q2 hasta el punto
r2y = y - Q2y; % elemento j del vector de Q2 hasta el punto

Ex = ke .* ( ( (Q1 .* r1x) ./ sqrt(r1x.^2 + r1y.^2).^2 ) + ( (Q2 .* r2x) ./ sqrt(r2x.^2 + r2y.^2).^2 ) );
Ey = ke .* ( ( (Q1 .* r1y) ./ sqrt(r1x.^2 + r1y.^2).^2 ) + ( (Q2 .* r2y) ./ sqrt(r2x.^2 + r2y.^2).^2 ) );

E = sqrt( Ex.^2 + Ey.^2 );

u = Ex./E;
v = Ey./E;

axis equal
quiver(x,y,u,v)%,'AutoScaleFactor',0.8)
hold on
grid on
title("Gráfica de Quiver")
xlabel("Eje x")
ylabel("Eje y")

rectangle('Position',[(Q1x-(Q1_d/2)) (Q1y-(Q1_d/2)) Q1_d Q1_d],'Curvature',[1,1],'FaceColor',[1 0 0],'EdgeColor',[1 0 0]);
rectangle('Position',[(Q2x-(Q2_d/2)) (Q2y-(Q2_d/2)) Q2_d Q2_d],'Curvature',[1,1],'FaceColor',[0 0 1],'EdgeColor',[0 0 1]);
text((Q2x-(Q2_d/2)),(Q2y-(Q2_d/2)),'-','Color','white','FontSize', 30);
axis([-5 10 -2 10]);