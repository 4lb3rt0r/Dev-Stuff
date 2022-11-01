% F1013B.4 - Modelación Computacional de Sistemas Eletromagnéticos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 23/Mayo/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE

%% Ejercicio 1
 f = @(x,y) -y + sin(x)
 
 A = 4
 B = 9.6
 H = 0.1
 y0 = -1
 
 % Llamar a la función RK4
 [x,y] = RK4(f,A,B,y0,H)
 figure("Name",'Ejercicio 1')
 plot(x,y,'.r')
 hold on
 % Llamar a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 plot(x,y,'og')
 hold on
 % Llamar a la función RK2_1
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 %Diseño de Gráfica
 title('Ejercicio 1')
 xlabel('x')
 ylabel('y')
 legend('Método RK4','Método RK2','Método RK2_1','Location','northwest')
 grid on
 disp('    X         Y         Sol. Analítica')
 disp([x' y' y2']) %transpuestas
 
 %% Ejercicio 2
 f = @(x,y) y * tan(x) + x
 
 A = 0
 B = 3
 H = 0.1
 y0 = 10
 
 % Llamar a la función RK4
 [x,y] = RK4(f,A,B,y0,H)
 figure("Name",'Ejercicio 2')
 plot(x,y,'.r')
 hold on
 % Llamar a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 plot(x,y,'og')
 hold on
 % Llamar a la función RK2_1
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 %Diseño de Gráfica
 title('Ejercicio 2')
 xlabel('x')
 ylabel('y')
 legend('Método RK4','Método RK2','Método RK2_1','Location','northwest')
 grid on
 disp('    X         Y         Sol. Analítica')
 disp([x' y' y2']) %transpuestas
 
  %% Ejercicio 3
 f = @(x,y) 3*x/y - x*y
 
 A = 0
 B = 2.5
 H = 0.1
 y0 = 2
 
 % Llamar a la función RK4
 [x,y] = RK4(f,A,B,y0,H)
 figure("Name",'Ejercicio 3')
 plot(x,y,'.r')
 hold on
 % Llamar a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 plot(x,y,'og')
 hold on
 % Llamar a la función RK2_1
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 %Diseño de Gráfica
 title('Ejercicio 3')
 xlabel('x')
 ylabel('y')
 legend('Método RK4','Método RK2','Método RK2_1','Location','northeast')
 grid on
 disp('    X         Y         Sol. Analítica')
 disp([x' y' y2']) %transpuestas
 
  %% Ejercicio 4
 f = @(x,y) y*cos(x)
 
 A = 0
 B = 4
 H = 0.1
 y0 = 1
 
 % Llamar a la función RK4
 [x,y] = RK4(f,A,B,y0,H)
 figure("Name",'Ejercicio 4')
 plot(x,y,'.r')
 hold on
 % Llamar a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 plot(x,y,'og')
 hold on
 % Llamar a la función RK2_1
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 %Diseño de Gráfica
 title('Ejercicio 4')
 xlabel('x')
 ylabel('y')
 legend('Método RK4','Método RK2','Método RK2_1','Location','northeast')
 grid on
 disp('    X         Y         Sol. Analítica')
 disp([x' y' y2']) %transpuestas
 