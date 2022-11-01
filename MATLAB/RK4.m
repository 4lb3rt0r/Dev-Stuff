%Fourth  Order Runge - Kutta
function [x,y] = RK4 (f,A,B,y0,H)
    x = [A:H:B]
    n = length(x)
    y = zeros(1,n)
    y(1) = y0
    
    for i = 1:n-1
        k1 = H * f(x(i),y(i))
        k2 = H * f(x(i) + H/2,y(i) + 1/2*k1)
        k3 = H * f(x(i)+ H/2,y(i) + 1/2*k2)
        k4 = H * f(x(i)+ H,y(i) + k3)
        y(i+1) = y(i) + 1/6 * (k1 + 2*k2 + 2*k3 + k4)
    end
end