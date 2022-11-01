function [xi,Iteraciones] = NewtonR(f,fdx,xi,error)
Iteraciones = 0
    while abs(subs(f,xi)) > error
        xi = xi - subs(f,xi)/subs(fdx,xi)
        Iteraciones = Iteraciones + 1
    end
    r = subs(f,xi)
    xi = double(xi)
    disp('Comprobación con el Método Newton-Raphson:')
    disp(xi)
end