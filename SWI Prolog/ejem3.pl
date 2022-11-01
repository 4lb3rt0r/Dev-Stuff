% L = [1,2,3,4].

% contar es una función que dada una lista L regresa la cantidad de elementos en la variable R.
%contar(L,R).

contar([],0).
% El | separa el primer elemento de la lista a la izquierda y el resto a la derecha
% El _ es una variable interna de Prolog
contar([_|Y],R) :- contar(Y,M), R is M+1.

% agrega = append L1+L2
agrega([],L2, L2).
agrega([H|L1],L2,[H|Z]) :- agrega(L1,L2,Z).

% reversa de una lista
reversa([],[]).
reversa([H|L],R) :- reversa(L,R1), agrega(R1,[H],R).

% miembro indicara si un elemento pertenece a una lista
miembro(M,[M|_]).
miembro(M, [_|T]) :- miembro(M,T).

% palindromo
palindromo(L) :- reversa(L,R), L=R.

% longitudPar regresará true si tiene cant de datos pal la lista
longitudPar(L) :- contar(L,R), R mod 2 =:= 0.