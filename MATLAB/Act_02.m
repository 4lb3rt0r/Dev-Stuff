% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 11/Abril/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE
%% Ejercicio 1

clc;
clear;
close all;

x = [-10 10] %Dejamos el intervalo como esta ya que solo existe una intersección con el eje x

f = @(x) x - cos(x)

figure("Name",'Ejercicio 1')
fplot(f)
title('Problema 1')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

[raiz,Iteraciones] = MetodoBiseccion(f,-10,10,0.1,x)
disp('Comprobación con el comando fzero:')
disp(fzero(f,x))
%% Ejercicio 2

clc;
clear;
close all;

x = [0.5 5] %Al tratarse de una gráfica cóncava hacia arriba existen 2 intersecciones en el eje de las x,
%por lo que reduje el rango a uno más preciso en donde solo exista una interseccion

f = @(x) x^2 - sin(x)

figure("Name",'Ejercicio 2')
fplot(f)
title('Problema 2')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

[raiz,Iteraciones] = MetodoBiseccion(f,0.5,5,0.1,x)
disp('Comprobación con el comando fzero:')
disp(fzero(f,x))
%% Ejercicio 3

clc;
clear;
close all;

x = [0.5 5] %Reduje el rango de forma que solo tomamos en cuenta un sección en la cual solo existe una interseccion con el eje de las x's

f = @(x) x*log(x)

figure("Name",'Ejercicio 3')
fplot(f)
title('Problema 3')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

[raiz,Iteraciones] = MetodoBiseccion(f,0.5,5,0.1,x)
disp('Comprobación con el comando fzero:')
disp(fzero(f,x))
%% Ejercicio 4

clc;
clear;
close all;

x = [0 3] %Reduje el rango de forma que solo tomamos en cuenta un sección en la cual solo existe una interseccion con el eje de las x's

f = @(x) exp(0.3)-(x.^2)

figure("Name",'Ejercicio 4')
fplot(f)
title('Problema 4')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

[raiz,Iteraciones] = MetodoBiseccion(f,0,3,0.1,x)
disp('Comprobación con el comando fzero:')
disp(fzero(f,x))
%% Ejercicio 5

clc;
clear;
close all;

x = [-10 10] %Dejamos el intervalo como esta ya que no presenta dificultades con tener varias intersecciones con el eje x
% x = [0 2] % Da un resultado similar al del intervalo [-10 10]
% x = [-3 -1] % Da un resultado aproximado al del intervalo [-10 10]
f = @(x) 2.*cos(x) - (x^1/2)/2

figure("Name",'Ejercicio 5')
fplot(f)
title('Problema 5')
xlabel('x')
ylabel('y')
legend('Valor de Trayectoria')
grid on
hline = refline(0,0)
hline.Color = 'r'

[raiz,Iteraciones] = MetodoBiseccion(f,-10,10,0.1,x)
disp('Comprobación con el comando fzero:')
disp(fzero(f,x))