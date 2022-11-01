function main
opcion = input("¿Qué desea hacer?\n','Teclee [1] para trasladar ó [2] para rotar.\n")
if opcion == 1
    fprintf('Teclee a continuación los valores del punto inicial y final de traslación en 2D\n')
    x0 = input("Valor de x0:\n")
    y0 = input("Valor de y0:\n")
    xf = input("Valor de xf:\n")
    yf = input("Valor de yf:\n")
    fprintf('Teclee a continuación los valores del punto inicial y final de traslación en 3D\n')
    x20 = input("Valor de x0:\n")
    y20 = input("Valor de y0:\n")
    z0 = input("Valor de z0:\n")
    x2f = input("Valor de xf:\n")
    y2f = input("Valor de yf:\n")
    zf = input("Valor de zf:\n")
    traslacion(x0,y0,xf,yf,x20,y20,z0,x2f,y2f,zf)
else if opcion == 2
    fprintf('Teclee a continuación los valores del punto, eje y grados de rotación en 2D\n')
    x = input("Valor de x\n")
    y = input("Valor de y\n")
    ang1 = input("Ángulo\n")
    fprintf('Teclee a continuación los valores del punto y grados de rotación en 3D\n')
    x2 = input("Valor de x\n")
    y2 = input("Valor de y\n")
    z = input("Valor de z\n")
    n = input("¿En qué eje está girando?\n","s")
    ang2 = input("Ángulo\n")
    rotacion(x,y,x2,y2,z,n,ang1,ang2)
else
    disp('Comando no reconocido :/')
end
end

function traslacion(x0,y0,xf,yf,x20,y20,z0,x2f,y2f,zf)
%2D
a = [1,0,xf;0,1,yf;0,0,1]
b = [x0;y0;1]
fprintf('Traslación de puntos en 2D:\n')
disp(a*b)
%3D
c = [1,0,0,x2f;0,1,0,y2f;0,0,1,zf;0,0,0,1]
d = [x20;y20;z0;1]
fprintf('Traslación de puntos en 3D:\n')
disp(c*d)
end

function rotacion(x,y,x2,y2,z,n,ang1,ang2)
%2D
a = [cosd(ang1),-sind(ang1);sind(ang1),-cosd(ang1)]
b = [x;y]
fprintf('Rotación de puntos en 2D:\n')
disp(a*b)
%3D
if n == "x"
    c = [1,0,0;0,cosd(ang2),-sind(ang2);0,sind(ang2),-cosd(ang2)]
    d = [x2;y2;z]
    fprintf('Rotación de puntos en 3D por el eje x:\n')
    disp(c*d)
elseif n == "y"
    c = [cosd(ang2),0,-sind(ang2);0,1,0;sind(ang2),0,-cosd(ang2)]
    d = [x2;y2;z]
    fprintf('Rotación de puntos en 3D por el eje x:\n')
    disp(c*d)
elseif n == "z"
    c = [cosd(ang2),-sind(ang2),0;sind(ang2),-cosd(ang2),0;0,0,1]
    d = [x2;y2;z]
    fprintf('Rotación de puntos en 3D por el eje x:\n')
    disp(c*d)
else 
    disp('Eje no válido')
end
end
end