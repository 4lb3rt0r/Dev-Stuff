% F1013B.4 - Modelación Computacional de Sistemas Eletromagnéticos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 18/Mayo/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE

%% Ejercicio 1

 f = @(t,x) t/sqrt(1 + t^2) + (0*x)
 
 A = 0
 B = 3.5
 H = 0.1
 y0 = 10
 
 % Llamar a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Ejercicio 1')
 plot(x,y,'.r')
 title('Ejercicio 1')
 xlabel('x')
 ylabel('y')
 legend('Trayectoria')
 grid on
 disp('    Tiempo     X    ')
 disp([x' y']) %transpuestas
 
 %% Ejercicio 1.2
 
 f = @(t,x) t/sqrt(1 + t^2) + (0*x)
 
 A = 0
 B = 3.5
 H = 0.1
 y0 = 10
 
 % Llamar a ka función RK2_1
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Ejercicio 1')
 plot(x,y,'ob')
 hold on
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 hold on
 a3 = 2/3
 [x,y3] = RK2_1(f,A,B,y0,H,a3)
 plot(x,y3,'og')
 hold on
 a4 = 1
 [x,y4] = RK2_1(f,A,B,y0,H,a4)
 plot(x,y4,'x')
 title('Ejercicio 1')
 xlabel('Tiempo (t)')
 ylabel('Variable (x)')
 legend('Aproximación 1','Aproximación 2','Aproximación 3','Aproximación 4','Location','northwest')
 grid on
 disp('    Tiempo   X         X (Aproximada) ')
 disp([x' y' y3']) %transpuestas
 
 %% Ejercicio 2
 
 f = @(t,y) sin(y) + (0*t)
 
 A = 0
 B = 3
 H = 0.1
 y0 = 1
 
 % Llamar a ka función RK2_1
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Ejercicio 2')
 plot(x,y,'ob')
 hold on
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 hold on
 a3 = 2/3
 [x,y3] = RK2_1(f,A,B,y0,H,a3)
 plot(x,y3,'og')
 hold on
 a4 = 1
 [x,y4] = RK2_1(f,A,B,y0,H,a4)
 plot(x,y4,'x')
 title('Ejercicio 2')
 xlabel('Tiempo (t)')
 ylabel('Variable (y)')
 legend('Aproximación 1','Aproximación 2','Aproximación 3','Aproximación 4','Location','northwest')
 grid on
 disp('    Tiempo   Y         Y (Aproximada) ')
 disp([x' y' y3']) %transpuestas
 
 %% Ejercicio 3
 
 f = @(t,y) 20 + 7 * sin(2*t)
 
 A = 0
 B = 2.8
 H = 0.1
 y0 = 15
 
 % Llamar a ka función RK2
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Ejercicio 3')
 plot(x,y,'ob')
 hold on
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 hold on
 a3 = 2/3
 [x,y3] = RK2_1(f,A,B,y0,H,a3)
 plot(x,y3,'og')
 hold on
 a4 = 1
 [x,y4] = RK2_1(f,A,B,y0,H,a4)
 plot(x,y4,'x')
 title('Ejercicio 3')
 xlabel('Tiempo (t)')
 ylabel('Variable (y)')
 legend('Aproximación 1','Aproximación 2','Aproximación 3','Aproximación 4','Location','northwest')
 grid on
 disp('    Tiempo   Y         Y (Aproximada) ')
 disp([x' y' y3']) %transpuestas
 
 %% Ejercicio 4
 
 f = @(x,y) 3*y - 4*exp(-x)
 
 A = 0
 B = 2
 H = 0.1
 y0 = 1
 
 % No es necesario llamar a la función RK2, ya que a4 = 1 como y0 = 1
 %[x,y] = RK2(f,A,B,y0,H)
 %figure("Name",'Ejercicio 4')
 %plot(x,y,'ob')
 %hold on
 a2 = 0.5
 [x,y] = RK2_1(f,A,B,y0,H,a2)
 figure("Name",'Ejercicio 4')
 plot(x,y,'ob')
 hold on
 a3 = 2/3
 [x,y2] = RK2_1(f,A,B,y0,H,a3)
 plot(x,y2,'pb')
 hold on
 a4 = 1
 [x,y3] = RK2_1(f,A,B,y0,H,a4)
 plot(x,y3,'og')
 hold on
 f2 = @(x) exp(-x) % solución analítica/ecuación exacta
 y4 = f2(x)
 plot(x,y4,'x')
 title('Ejercicio 4')
 xlabel('Variable (x)')
 ylabel('Variable (y)')
 legend('Aproximación 1','Aproximación 2','Aproximación 3','Ecuación Exacta (Solución Analítica)','Location','southwest')
 grid on
 disp('    X    Y(Aproximación)  Sol. Analítica')
 disp([x' y3' y4']) %transpuestas
 
 %% Ejercicio 5
 
 f = @(x,y) (y + 1) * (x + 1) * cos(x^2 + 2*x)
 
 A = 0
 B = 2
 H = 0.1
 y0 = 4
 
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Ejercicio 5')
 plot(x,y,'ob')
 hold on
 a2 = 0.5
 [x,y2] = RK2_1(f,A,B,y0,H,a2)
 plot(x,y2,'pb')
 hold on
 a3 = 2/3
 [x,y3] = RK2_1(f,A,B,y0,H,a3)
 plot(x,y3,'og')
 hold on
 a4 = 1
 [x,y4] = RK2_1(f,A,B,y0,H,a4) 
 plot(x,y4,'x')
 hold on
 f2 = @(x) 5 * exp(1/2 * sin(x.^2 + 2*x)) - 1
 y5 = f2(x)
 plot(x,y5,'d')
 title('Ejercicio 5')
 xlabel('Variable (x)')
 ylabel('Variable (y)')
 legend('Aproximación 1','Aproximación 2','Aproximación 3','Aproximación 4','Ecuación Exacta (Solución Analítica)','Location','southwest')
 grid on
 disp('    X      Y(Aproximación)  Sol. Analítica')
 disp([x' y2' y4']) %transpuestas