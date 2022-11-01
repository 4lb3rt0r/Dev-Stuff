%Second  Order Runge - Kutta
function [x,y] = RK2_1 (f,A,B,y0,H,a2)
    x = [A:H:B]
    n = length(x)
    y = zeros(1,n)
    y(1) = y0
    
    %Heun, a2 = 1/2; Ralston. a2 = 2/3; Punto Medio, a2 = 1
    
    a1 = 1 - a2
    p1 = 1/2*a2
    q11 = p1
    
    for i = 1:n-1
        k1 = f(x(i),y(i))
        k2 = f(x(i) + p1* H,y(i) + q11 *k1*H)
        y(i+1) = y(i) + (a1 * k1 + a2 * k2)*H
    end
end