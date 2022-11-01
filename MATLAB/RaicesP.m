%Raíces de Polinomios con regla de Ruffini

function r = RaicesP(A)
    terminoI = A(end);
    Divisores = divisors(terminoI);
    Divisores = [Divisores Divisores * -1];
    NuevaA(1) = A(1); % Reservamos primer elemento de los coeficientes
    r = [ ];
    for i = 1:length(Divisores)
        Div = Divisores(i); %Elegimos un divisor
        Mul(1) = Div * NuevaA(1); %Multiplicacion
        for j=2:length(A)
            NuevaA(j) = A(j) + Mul(j-1); %Suma
            Mul(j) = Div * NuevaA(j); %Multiplicacion
        end
        if NuevaA(end)==0
            r = [r,Div]; %Guardar el divisor que si es raiz
            NuevaA(end)=[ ]; %Reiniciamos el vector para guardar la raíz
            A = NuevaA;
        end
    end 
end