% Implementación de Métodos Computacionales
% Nombre: Alberto Horacio Orozco Ramos
% Matrícula: A00831719
% Fecha: 29/Mayo/2022
% Actividad: Act 5.2

% -import(math, [sqrt/1]).
% -import(timer, [now_diff/2]).

-module(suma).

-import(math, [sqrt/1]).
-import(timer, [now_diff/2]).

-export([start/1]).
-export([suma/1]).
-export([primoAux/2]).

start(N) ->
    T1 = time(),
    suma(N),
    T2 = time(),
    Diff = now_diff(T1, T2),
    io:format(Diff).

suma(N) -> if
    N == 0 -> 0;
    primoAux(N,2) -> N + suma(N-1);
    true -> suma(N-1)
end.

primoAux(N,X) -> if
    X > sqrt(N) -> true;
    N rem X == 0 -> false;
    true -> primoAux(N,X+2)
end.
