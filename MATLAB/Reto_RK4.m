%Parámetros Iniciales
a = 0.1
b = 0.2
%Condiciones Iniciales
t0 = 0
tf = 20
x0 = 5000
y0 = 0
%Vector del Tiempo
H = 0.5
t = t0:h:tf
%Inicializando vectores para sustancias A y B
x = zeros(1,length(t))
y = zeros(1,length(t))
x(1) = x0
y(1) = y0
%Declaraciones de funciones
f1 = @(t,x,y) -a*x
f2 = @(t,x,y) a*x- b*y

%Implementar RK4
for i = 1:(length(t)-1)
    k1 = H * f1(t(i),x(i),y(i))
    l1 = H * f2(t(i),x(i),y(i))
    
    k2 = H * f1(t(i) + H/2,x(i)+ k1/2,y(i) + 1/2*l1)
    l2 = H * f2(t(i) + H/2,x(i)+ k1/2,y(i) + 1/2*l1)
    
    k3 = H * f1(t(i) + H/2,x(i)+ k2/2,y(i) + 1/2*l2)
    l3 = H * f2(t(i) + H/2,x(i)+ k2/2,y(i) + 1/2*l2)
    
    k4 = H * f1(t(i)+ H,x(i)+ k3,y(i) + k3)
    l4 = H * f2(t(i)+ H,x(i)+ k3,y(i) + l3)
    
    x(i+1) = x(i) + 1/6 * (k1 + 2*k2 + 2*k3 + k4)
    y(i+1) = y(i) + 1/6 * (l1 + 2*l2 + 2*l3 + l4)
end

%Graficacion
plot(t,x)
xlabel('Tiempo (años)')
ylabel('Número de Núcleos')
title('Sustancia A')
grid on