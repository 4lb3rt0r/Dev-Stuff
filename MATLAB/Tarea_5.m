function main
clear;
clc;
fprintf("Para proceder con la resolución del sistema de ecuaciones,\n debemos identificar una ecuación Ax = b\n")
n = input("¿Cuántas filas tiene tu matriz [A]?\n")
n2 = input("¿Cuántas columnas tiene tu matriz [A]?\n")
A = []
b = []
for i = 1:n
 for j = 1:n2
  a = input("Ingrese un número:\n")
  A(i,j) = a
 end
end
fprintf("Introduce a continuación los valores de tu matriz [b]:\n")
for i = 1:n
 for j = 1:1
  a = input("Ingrese un número:\n")
  b(i,j) = a
 end
end
n = length(b)
Gauss_Jacobi(A,b,n)
Gauss_Seidel(A,b,n)
end

function Gauss_Jacobi(A,b,n)
D = diag((diag(A)).')
L = tril(A)-D
U = triu(A)-D
T = -inv(D)*(L+U)
c = inv(D)*b
x = zeros(n,1)
xi = 1
x2 = zeros(n,1)
%v = true
count = 0

while abs(xi-x2) > (10^-6)
    xi = (T*x) + c 
    x2 = x
    x = xi
    count = count + 1
end
%while v ~= false   Este código no me funcionó :(
 %xi = (T*x) + c 
 %for i = 1:n
  %error(i,1) = (abs(xi(i,1)-x(i,1)))/xi(i,1)
 %end
 %x = xi
 %count = count + 1 
 %if error == x2
  %   v = false
 %end
%end
end

function Gauss_Seidel(A,b,n)  %Los resultados son muy aproximados
D = diag((diag(A)).')
L = tril(A)-D
U = triu(A)-D
Tg = (-inv(D-L))*U
cg = (inv(D-L))*b
x = zeros(n,1)
xi = 1
x2 = zeros(n,1)
count = 0
while abs(xi-x2) > (10^-6)
    xi = (Tg*x) + cg
    x2 = x
    x = xi
    count = count + 1
end

end