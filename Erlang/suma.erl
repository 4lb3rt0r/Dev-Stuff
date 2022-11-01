% Implementación de Métodos Computacionales
% Nombre: Alberto Horacio Orozco Ramos
% Matrícula: A00831719
% Fecha: 29/Mayo/2022
% Actividad: Act 5.2

% cd("C:/Users/alber/Documents/GitHub/Actividad-Integradora-5.3-Proyecto-paralelo").
% cd("C:/Users/alber/Desktop/Alberto/Programacion/Erlang")
% c(suma).
% suma:suma(5000000,2,0).
% suma:runSeq().
% suma:runConc().

% Inicializamos el modulo del archivo de Erlang "suma"
-module(suma).

% Importamos las librerías necesarias para realizar cálculos matemáticos
-import(math,[sqrt/1]).
-import(timer,[now_diff/2]).

% Declaramos todas las funciones necesarias con su respectiva cantidad de parámetros a recibir
-export([runSeq/0]).
-export([runConc/0]).
-export([runConcHelper/2]).
-export([suma/3]).
-export([sumaux/3]).

% Algoritmo de O() (no se repite ni existe recursividad, entonces considero que no posee ningún orden)
% Inicializamos variables dentro de la funcion runSeq() e imprimimos los resultados de suma y tiempo con programacion secuencial
runSeq() -> 
	T1 = time(),
	Res = suma(5000000,2,0),
	T2 = time(),
	Diff = now_diff(T2,T1),
	io:format("Suma: ~p ~n", [Res]),
	io:format("Tiempo: ~p ~n", [Diff]).

% Algoritmo de O(1)
% Asistente de runConc() (programación paralela)
runConcHelper(N, S) ->
	T1 = time(),
	Res = suma(N,S,0),
	T2 = time(),
	Diff = now_diff(T2,T1),
	io:format("Suma: ~p ~n", [Res]),
	io:format("Tiempo: ~p ~n", [Diff]).

% Algoritmo de O(1)
% runConc() llama a su asistente y le envía diversos valores (procesos), esto mediante programación paralela
runConc() ->  
	spawn(suma, runConcHelper,[1250000, 2]),
	spawn(suma, runConcHelper,[2500000, 1250000]),
	spawn(suma, runConcHelper,[3750000, 2500000]),
	spawn(suma, runConcHelper,[5000000, 3750000]).
	
% Algoritmo de O(n)
% Primer caso de suma() cuando S (raíz de N) sea menor o igual a N (cualquier número)
suma(N,S,Sum) when S =< N ->
	case sumaux(N,sqrt(N),2) of
		true -> suma(N-1,S,Sum+N);
		_ -> suma(N-1,S,Sum)
	end;

% Algoritmo de O(n^2)
% Segundo caso de suma() cuando tienes cualquier cosa en los 2 primeros parámetros y la variable de Sumatoria
suma(_,_,Sum) -> Sum.

% Algoritmo de O(1)
% Asistente de suma() que ayuda a determinar si el número es primo o no
sumaux(N,R,X) -> if
	X > R -> true;
	N rem X == 0 -> false;
	true -> sumaux(N,R,X+1)
end.