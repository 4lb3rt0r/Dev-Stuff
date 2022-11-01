% F1013B.4 - Modelación Computacional de Sistemas Eletromagnéticos
% Profesor: Héctor Hernández de la Cerda
% Alumno: Alberto Horacio Orozco Ramos      Matrícula: A00831719
% Fecha: 6/Junio/21

% RESOLUCIÓN DE EJERCICIOS DE CLASE

%% Ejercicio 1

% Paso 1. Abrir el archivo PuntosEntrenamiento.csv
matriz = readmatrix('PuntosEntrenaCurva1.csv')

% Paso 2. Primer renglón en x, segundo renglón en y
x = matriz(1,:)
y = matriz(2,:)

% Paso 3. Leer archivo PuntosPrueba.csv
matriz2 = readmatrix('PuntosPruebaCurva1.csv')

% Paso 4. Primer renglón en x2, segundo renglon en y2
x2 = matriz2(1,:)
y2 = matriz2(2,:)

% Paso 5. x vs y (datos originales)
figure("Name",'Ejercicio 1')
plot(x,y,'.r')
hold on
plot(x2,y2,'.m')
grid on

% Paso 6. Cálculo del Polinomio de Grado N
C = polyfit(x,y,5)

% Paso 7. Evaluación del Polinomio en Datos de Prueba
yy = polyval(C,x)

% Paso 8. Graficar el Polinomio de Ajuste
plot(x,yy,'-b')
hold on
% Paso 9. Cálculo Analítico del Error Cuadrático Medio (MSE) (y-yy)
disp('MSE de los Datos Entrenamiento es:')
mse(y-yy)

% Paso 10. Evaluación del Polinomio en Datos de Entrenamiento
yy2 = polyval(C,x2)

% Paso 11. Graficar el Polinomio de Ajuste
plot(x2,yy2,'-r')

% Formato predeterminado de la Gráfica
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title('Puntos Prueba 1 y Entrena 1')
legend('Polinomio de Grado 5','Location','northwest')

% Paso 12. Cálculo Analítico del Error Cuadrático Medio (MSE) (y2-yy2)
disp('MSE de los Datos Prueba es:')
mse(y2-yy2)

%% Ejercicio 2

% Paso 1. Abrir el archivo PuntosEntrenamiento.csv
matriz = readmatrix('PuntosEntrenaCurva2.csv')

% Paso 2. Primer renglón en x, segundo renglón en y
x = matriz(1,:)
y = matriz(2,:)

% Paso 3. Leer archivo PuntosPrueba.csv
matriz2 = readmatrix('PuntosPruebaCurva2.csv')

% Paso 4. Primer renglón en x2, segundo renglon en y2
x2 = matriz2(1,:)
y2 = matriz2(2,:)

% Paso 5. x vs y (datos originales)
figure("Name",'Ejercicio 2')
plot(x,y,'.r')
hold on
plot(x2,y2,'.m')
grid on

% Paso 6. Cálculo del Polinomio de Grado N
C = polyfit(x,y,5)

% Paso 7. Evaluación del Polinomio en Datos de Prueba
yy = polyval(C,x)

% Paso 8. Graficar el Polinomio de Ajuste
plot(x,yy,'-b')
hold on
% Paso 9. Cálculo Analítico del Error Cuadrático Medio (MSE) (y-yy)
disp('MSE de los Datos Entrenamiento es:')
mse(y-yy)

% Paso 10. Evaluación del Polinomio en Datos de Entrenamiento
yy2 = polyval(C,x2)

% Paso 11. Graficar el Polinomio de Ajuste
plot(x2,yy2,'-r')

% Formato predeterminado de la Gráfica
xlabel('Eje de las Xs')
ylabel('Eje de las Ys')
title('Puntos Prueba 2 y Entrena 2')
legend('Polinomio de Grado 5','Location','northwest')

% Paso 12. Cálculo Analítico del Error Cuadrático Medio (MSE) (y2-yy2)
disp('MSE de los Datos Prueba es:')
mse(y2-yy2)