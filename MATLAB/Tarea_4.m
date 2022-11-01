function main
clear;
clc;
fprintf("Para proceder con la resolución del sistema de ecuaciones,\n debemos identificar una ecuación Ax = b\n")
n = input("¿Cuántas filas tiene tu matriz [A]?\n")
n2 = input("¿Cuántas columnas tiene tu matriz [A]?\n")
A = []
b = []
%var = []
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
fprintf("Ingrese a continuación las variables de sus ecuaciones en orden:\n")
%for k = 1:n
 %v = input('Ingrese una variable:\n','s')
 %var(k) = char(v)
%end
cramer(A,b,n)
%gauss_jordan(A,b,n)
end

function cramer(A,b,n)
rango = rank(A)
rango2 = rank([A,b])
if rango == rango2
 for i = 1:n
  A1 = A
  A1(:,i) = b
  cramer(i) = det(A1)/det(A)
  %disp('El valor de ',var(i),' es',r)
 end
else
    disp("Los rangos entre ambas matrices no coinciden :/")
end
end

function gauss_jordan(A,b,n)
C = [A,b]
for i=1:n
       for j=1:i
           if (j < i)
               m = C(i,j);
               if C(i,j) == 1 || C(i,j) == 0
                   fprintf('NOT no funciona junto al OR, por lo que hay un IF no tan effectivo');
               else
                   for k=1:n+1
                       C(i,k) = C(i,k) / m;
                   end
               end
               if C(i,j) ~= 0
                   for k=1:n+1
                       C(i,k) = C(i,k) - C(j,k);
                   end
               end
               
           else 
               if C(i,j) == 1 || C(i,j) == 0
                   fprintf('NOT no funciona junto al OR, por lo que hay un IF no tan efectivo');
               else
                   m = C(i,j);
                   for k=1:n+1
                       C(i,k) = C(i,k) / m;
                   end
               end
           end
           C
       end
    end
    %QUICK WAY TO SOLVE IT
    %{
    E = rref(S)
    %}
    res = ones(1,n);
    res = [res,1];
    for i=n:-1:1
        C(i,:) = C(i,:).*res
        for j=n:-1:i
            if (j == i)
                sol = C(i,n+1) / C(i,j);
                res(1,i) = sol;
            end
            C(i,n+1) = C(i,n+1) - C(i,j);
        end
    end
    
    for i=1:n
        fprintf('Un resultado de Gauss-Jordan es: %s \n', strtrim(rats(res(1,i))));
    end
end