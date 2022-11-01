clc; clear; close all
%F1013B gpo 4 Modelacion Computacional de Sistemas Electricos
%
%
ke = 8.9876 * 10 ^9;

% Informacion de las cargas
Q1 = 10; % Input
Q2 = -Q1;
Q1x = 0; % Posicion en X  Input
Q2x = 4; % Posicion en Y  Input
lim_1 = 4; % Limite de la carga 1  input
lim_2 = 4; % Limite de la carga 2  input
num_cargas = 10; % input
Q_d = 1; % Diametro del circulo en la grafica

% Vectores de los puntos en Y para las cargas
Q1_pos = linspace(-lim_1, lim_1, num_cargas);
Q2_pos = linspace(-lim_2, lim_2, num_cargas);

% Crear el meshgrid
figure("name","Quiver")
x = linspace(-5,15,30);
y = linspace(-5,15,30);
[x,y] = meshgrid(x, y);

% Crear matriz vacia
Ex = zeros(30);
Ey = zeros(30);

hold on
% Darle valor a la matriz vacia
for i = 1:num_cargas
    r1x = x - Q1x;
    r1y = y - Q1_pos(i);
    r2x = x - Q2x;
    r2y = y - Q2_pos(i);
    
    Ex = Ex + ke .* ( (Q1 .* r1x) ./ sqrt(r1x.^2 + r1y.^2).^3 );
    Ex = Ex + ke .* ( (Q2 .* r2x) ./ sqrt(r2x.^2 + r2y.^2).^3 );
    
    Ey = Ey + ke .* ( (Q1 .* r1y) ./ sqrt(r1x.^2 + r1y.^2).^3 );
    Ey = Ey + ke .* ( (Q2 .* r2y) ./ sqrt(r2x.^2 + r2y.^2).^3 );
end

% Calcular la magnitud del campo eléctrco
E = sqrt( Ex.^2 + Ey.^2 );
    
u = Ex./E;
v = Ey./E;

axis equal
% Graficar Quiver
qui = quiver(x,y,u,v);

for j = 1:num_cargas
    rectangle('Position',[(Q1x-(Q_d/2)) (Q1_pos(j)-(Q_d/2)) Q_d Q_d],'Curvature',[1,1],'FaceColor',[1 0 0],'EdgeColor',[1 0 0]);
    rectangle('Position',[(Q2x-(Q_d/2)) (Q2_pos(j)-(Q_d/2)) Q_d Q_d],'Curvature',[1,1],'FaceColor',[0 0 1],'EdgeColor',[0 0 1]);
end

title("Gráfica de Quiver")
xlabel("Eje x")
ylabel("Eje y")
hline = refline(0,0);
hline.Color = 'black';
axis([-5 10 -5 10]);
