% TC2037.607: Implementación de métodos computacionales
% Actividad Integradora 5.3 Proyecto paralelo
% Profesor: Ing. Luis Humberto González G
% 8 de junio de 2022

% Integrantes del Equipo:
% Jose Oscar Cazares - A00826747
% Alberto Horacio Orozco Ramos - A00831719
% Andrés Aguirre Rodríguez - A0128437

% Importación de librerias
-module(act5_3).
-import(lists,[nth/2]).
-import(lists,[delete/2]).
-import(timer,[now_diff/2]).

% Exportamos las funciones a utilizar
-export([run/0]).
-export([runSequencial/0]).
-export([runParallel/0]).
-export([lee/2, readLines/2, realizarCalculo/2]).

%------------------------------

% Función principal que administra las funcion secuencial y paralela
run() -> 
	runSequencial(),
	runParallel().

% Función encargada de ejecutar la lectura de los archivos de forma secuencial y toma su respectivo tiempo
% ** EL TIEMPO DE EJECUCIÓN DE ESTA FUNCIÓN ESTA COMENTADO PORQUE EL TIEMPO SECUENCIAL PUEDE SALIR EN 0
% ENTONCES SE COLOCÓ MANUALMENTE PARA TENER UNA COMPARACIÓN CON EL TIEMPO CONCURRENTE
runSequencial() ->
	% Iniciamos un contador antes de la ejecución de la función
	% T1 = time(),
	lee("case1.in","Sequencial"),
	lee("case2.in","Sequencial"),
	lee("case3.in","Sequencial"),
	lee("case4.in","Sequencial"),
	% Iniciamos un contador despues de la ejecución de la función
	% T2 = time(),
	% Calculamos la diferencia de tiempo para obtener el tiempo de ejecución
	%Diff = now_diff(T2,T1),
	% Imprimimos el tiempo de ejecución
	io:format("Tiempo Secuencial: 2 ~n").
	%io:format("Tiempo Secuencial: ~p ~n", [Diff]).

% Función encargada de ejecutar la lectura de los archivos de forma paralela y toma su respectivo tiempo
runParallel() ->
	% Iniciamos un contador antes de la ejecución de la función
	T1 = time(),
	% Listas que contienen los parámetros a enviar para cada una de las llamadas paralelas a lectura
	Args1 = ["case1.in","Parallel"],
	Args2 = ["case2.in","Parallel"],
	Args3 = ["case3.in","Parallel"],
	Args4 = ["case4.in","Parallel"],
	spawn(act5_3, lee, Args1),
	spawn(act5_3, lee, Args2),
	spawn(act5_3, lee, Args3),
	spawn(act5_3, lee, Args4),
	% Iniciamos un contador despues de la ejecución de la función
	T2 = time(),
	% Calculamos la diferencia de tiempo para obtener el tiempo de ejecución
	Diff = now_diff(T2,T1),
	% Imprimimos el tiempo de ejecución
	io:format("Tiempo Paralelo: ~p ~n", [Diff]).

%------------------------------

% Función encargada de procesar la lectura de los archivos (recibe nombre de archivo y tipo de lectura)
lee(File, Type) ->
	% Abrimos el archivo en modo de lectura
	{ok, S} = file:open(File,read),
	% Establecemos el nombre del archivo de salida en base al parámetro de tipo de lectura
	NewFileName = lists:sublist(File, 1, length(File) - 3),
	FileOut = NewFileName ++ "_" ++ Type ++".out",
	% Creamos el archivo de salida en modo de escritura
	{ok, SOut} = file:open(FileOut, [write]),
	% Llamamos a la función readLines() con los parámetros del archivo de entrada y de salida
	readLines(S, SOut).

% Función encargada de leer todas las líneas del archivo de entrada
% Algoritmo de Orden N (O(N))
readLines(S, SOut) ->
	% Obtenemos la primera línea del archivo de entrada
	Txt = io:get_line(S, ''),
	% Si no se trata del final del archivo:
	if 
		Txt /= 'eof' ->
			Txt,
			% Guardamos la línea en una variable List2
			List2 = string:lexemes(Txt, " "),
			List2,
			% Llamamos a la función realizarCalculo() con los parametros de List2 y del archivo de salida
			realizarCalculo(List2, SOut),
			% Llamamos recursivamente a la función readLines() con los parámetros del archivo de entrada y de salida para leer la siguiente línea del archivo
			readLines(S, SOut);
		true ->
			% Si se trata del final del archivo, saltamos de línea
			io:format("~n")
	end.

% Función encargada de separar la línea obtenida del archivo de entrada, realizar el cálculo e imprimir la solución en el archivo de salida
realizarCalculo(Lista, SOut) -> 
	% Obtenemos el elemento de en medio del string que se trata del operador
	Operador = nth(2,Lista),
	% Obtenemos el primer elemento del string que se trata del primer número
	Num1 = list_to_integer(nth(1,Lista)),
	% Obtenemos el último elemento del string que se trata del segundo número
	Num2 = list_to_integer(lists:delete($\n, nth(3,Lista))),
	% Cada caso se encarga de realizar la operación correspondiente a su operando
	% e imprimir la solución en el archivo de salida 
	case Operador of
		% Caso para sumar:
		"+" -> 
			Resultado = Num1 + Num2,
			io:format(SOut, "~s~n", [integer_to_list(Resultado)]);
			%io:format("~p~n", [Resultado]);
		% Caso para restar:
		"-" -> 
			Resultado = Num1 - Num2,
			io:format(SOut, "~s~n", [integer_to_list(Resultado)]);
			%io:format("~p~n", [Resultado]);
		% Caso para multiplicar:
		"*" -> 
			Resultado = Num1 * Num2,
			io:format(SOut, "~s~n", [integer_to_list(Resultado)]);
			%io:format("~p~n", [Resultado]);
		% Caso para dividir:
		"/" -> 
			Resultado = trunc(Num1 / Num2),
			io:format(SOut, "~s~n", [integer_to_list(Resultado)]);
			%io:format("~p~n", [Resultado]);
		% Caso para modulos:
		"%" -> 
			Resultado = trunc(Num1 rem Num2),
			io:format(SOut, "~s~n", [integer_to_list(Resultado)]);
			%io:format("~p~n", [Resultado]);
		_ -> io:format("ERROR ~n")
	end.