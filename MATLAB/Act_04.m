% F1013B.4 - Modelación Computacional de Sistemas Elétricos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 25/Abril/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE
%% Ejercicio 1

clear; 
clc;
close all;

f = @(x) x.^3 - 6. * x.^2 + 11. * x - 6

figure("Name","Ejemplo 1")
fplot(f)
hold on
c = [1 -6 11 -6]
sol = roots(c)
plot(sol,0,'pk') %or
title("Ecuacion 1 Ejemplo")
xlabel("Eje de las x")
ylabel("Eje de las y")
xlim ([0 4])
ylim([-5 5])
hline = refline(0,0)
hline.Color = 'r'    
grid on

%% Ejercicio 2

clear; 
clc;
close all;

f = @(x) x.^3 - x.^2 - 4. * x + 4

figure("Name","Ejemplo 2")
fplot(f)

hold on
A = [1 -1 -4 4]
r = RaicesP(A); %llamando a la función RaicesP

disp('Las raices son: ')
disp(r)

a = f(r)
plot(r,a,'pk') %or
title("Ecuacion 2 Ejemplo")
xlabel("Eje de las x")
ylabel("Eje de las y")
xlim ([-3 3])
ylim([-20 20])
hline = refline(0,0)
hline.Color = 'r'    
grid on

%% Ejercicio 3

clear; 
clc;
close all;

f = @(x) -x.^4 + 10.*x.^2 - 9

figure("Name","Ejemplo 3")
fplot(f)

hold on
A = [-1 0 10 0 -9]
r = RaicesP(A); %llamando a la función RaicesP

disp('Las raices son: ')
disp(r)

a = f(r)
plot(r,a,'pk') %or
title("Ecuacion 3 Ejemplo")
xlabel("Eje de las x")
ylabel("Eje de las y")
xlim ([-4 4])
ylim([-20 20])
hline = refline(0,0)
hline.Color = 'r'    
grid on

%% Ejercicio 4

clear; 
clc;
close all;

f = @(x) 2.*x.^3 + x.^2 - 13. * x + 6

figure("Name","Ejemplo 4")
fplot(f)

hold on
A = [2 1 -13 6]
r = RaicesP(A); %llamando a la función RaicesP

disp('Las raices son: ')
disp(r)

a = f(r)
plot(r,a,'pk') %or
title("Ecuacion 4 Ejemplo")
xlabel("Eje de las x")
ylabel("Eje de las y")
xlim ([-3.5 3])
ylim([-10 30])
hline = refline(0,0)
hline.Color = 'r'    
grid on