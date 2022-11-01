% Metodo de Jacobi

% Ingresar Datos
x1 = input("Ingresa el primer termino que acompaña a x: ");
y1 = input("Ingresa el primer termino que acompaña a y: ");
z1 = input("Ingresa el primer termino que acompaña a z: ");

x2 = input("Ingresa el segundo termino que acompaña a x: ");
y2 = input("Ingresa el segundo termino que acompaña a y: ");
z2 = input("Ingresa el segundo termino que acompaña a z: ");

x3 = input("Ingresa el tercer termino que acompaña a x: ");
y3 = input("Ingresa el tercer termino que acompaña a y: ");
z3 = input("Ingresa el tercer termino que acompaña a z: ");

eq1 = input("Ingresa el resultado de la primera ecuación: ");
eq2 = input("Ingresa el resultado de la segunda ecuación: ");
eq3 = input("Ingresa el resultado de la tercera ecuación: ");

% Desarrollo de Jacobi
% Creación de Matrices
x = [0 0 0]';
A = [x1 y1 z1; x2 y2 z2; x3 y3 z3];
b = [eq1; eq2; eq3];

%Implementación Jacobi
D = diag(diag(A));
L = tril(A, -1);
U = triu(A, 1);

% Loop para las iteraciones
xo = 1;
xi = x;

while abs(xo-xi) > 10^-6
    xo = -inv(D)*(L+U)*x+inv(D)*b; % En si el metodo de el buen Jacobi
    xi = x;
    x = xo;
end
xo