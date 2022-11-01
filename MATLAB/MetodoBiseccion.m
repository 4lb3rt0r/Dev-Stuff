function [raiz,Iteraciones] = MetodoBiseccion(f,xi,xf,Err,x)
Iteraciones = 0
raiz = NaN %Not a number (no esta definido o no es un número)
xm = (xi+xf)/2
if f(xi)*f(xf)< 0 %condicional para revisar si hay 0's en el intervalo
    while abs(f(xf)-f(xi)) > Err
        if f(xi)*f(xm) < 0
            xf = xm
        else
            xi = xm
        end
        Iteraciones = Iteraciones + 1
        xm = (xi + xf) / 2
    end
    raiz = xm
else 
    disp('Pruebe con otro intervalo :/')
end
end