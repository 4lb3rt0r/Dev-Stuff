% F1013B.4 - Modelación Computacional de Sistemas Electromagnéticos
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 9/Junio/2021

% RESOLUCIÓN DE PREGUNTA 2 - EXAMEN ARGUMENTATIVO ESCRITO

%% Pregunta 2 - Inciso 2: H = 0.1

 f = @(x,y) y + 2.*x - x.^2
 
 A = 0
 B = 10
 H = 0.1
 y0 = 1
 
 % Llamamos a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Pregunta 2')
 plot(x,y,'.r')
 title('Inciso 2 con H = 0.1 - Pregunta 2')
 xlabel('x')
 ylabel('y')
 legend('Trayectoria - H = 0.1')
 grid on
 disp('    X         Y    ')
 disp([x' y']) %transpuestas
 
 %% Pregunta 2 - Inciso 2: H = 0.5

 f = @(x,y) y + 2.*x - x.^2
 
 A = 0
 B = 10
 H = 0.5
 y0 = 1
 
 % Llamamos a la función RK2
 [x,y] = RK2(f,A,B,y0,H)
 figure("Name",'Pregunta 2')
 plot(x,y,'.r')
 title('Inciso 2 con H = 0.5 - Pregunta 2')
 xlabel('x')
 ylabel('y')
 legend('Trayectoria - H = 0.5')
 grid on
 disp('    X         Y    ')
 disp([x' y']) %transpuestas