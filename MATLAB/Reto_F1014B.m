% Equipo 4: 				
% Daniel Degollado Rodríguez 		A00832555
% Yael Ariel Márquez Mas            A01745310
% Kailin Wu                         A00830574
% Alberto Horacio Orozco Ramos      A00831719
% Müsel Emmanuel Tabares Pardo      A00830710

clear;
clc;
close all;

%Inicializamos las variables y constantes
u0 = (4*pi)*10^-7;
I = 5;
a = 1; 
l = (u0/2*pi);

% Puntos de la gráfica
Py = linspace(0,2.1,30);
Pz = linspace(0,2.1,30);
phi = linspace(0,2*pi,30);
[y,z,P] = meshgrid(Py,Pz,phi);

% Diferencial de Y y de Z del campo megnético
dBy = @(p) (sin(p))./(a.^2+z.^2+y.^2 -(2.*a.*y.*sin(p))).^(3/2);
dBz = @(p) (a-y.*sin(p))./((a.^2 + z.^2 + y.^2 - 2.*a.*y.*sin(p))).^(3/2);

% Evaluación de los diferenciales con el ángulo phi
Y = dBy(P);
Z = dBz(P);

% Integrales de los diferenciales de Y y de Z
Int1 = trapz(phi,Y,3);
Int2 = trapz(phi,Z,3);

% Campo magnético en Y y en Z
By = l.*I.*a.*z .* Int1;
Bz = l.*I.*a .* Int2;

% Magnitud del campo magnético
B = sqrt(Bz.^2 + By.^2);

% Gráfica del campo magnético
hold on;
quiver(y,z,By./B,Bz./B,0.8);
plot(a,0,'.r');
xlim([0 2]);
ylim([0 2]);