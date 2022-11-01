function [m,b] = minimosC(x,y)
    n = length(x)
    Ex = sum(x)
    Ey = sum(y)
    Exy = sum(x.*y)
    Ex2 = sum(x.^2)
    
    m = (Exy - ((Ex*Ey)/n))/(Ex2 - (Ex.^2/n))
    b = (Ey/n) - m * (Ex/n)
end