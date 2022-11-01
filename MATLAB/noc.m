clear;
clc;
n = 3
fprintf("Ingrese a continuación las variables de sus ecuaciones en orden:\n")
for k = 1:n
 v = input('Ingrese una variable:\n','s')
 var(k) = char(v)
end
var(1)