% Andres Aguirre Rodriguez - A01284373

-module(primo).

-import(math,[sqrt/1]).
-import(timer,[now_diff/2]).

-export([runSeq/0]).
-export([runConc/0]).
-export([runConcHelper/2]).
-export([primo/3]).
-export([primoaux/3]).

%complejidad: 
runSeq() -> 
	T1 = time(),
	Res = primo(5000000,2,0),
	T2 = time(),
	Diff = now_diff(T2,T1),
	io:format("Suma: ~p ~n", [Res]),
	io:format("Tiempo: ~p ~n", [Diff]).

%complejidad: 1
runConcHelper(N, S) ->
	T1 = time(),
	Res = primo(N,S,0),
	T2 = time(),
	Diff = now_diff(T2,T1),
	io:format("Suma: ~p ~n", [Res]),
	io:format("Tiempo: ~p ~n", [Diff]).

%complejidad: 1
runConc() ->  
	spawn(primo, runConcHelper,[1250000, 2]),
	spawn(primo, runConcHelper,[2500000, 1250000]),
	spawn(primo, runConcHelper,[3750000, 2500000]),
	spawn(primo, runConcHelper,[5000000, 3750000]).
	
%complejidad: N
primo(N,S,Sum) when S =< N ->
	case primoaux(N,sqrt(N),2) of
		true -> primo(N-1,S,Sum+N);
		_ -> primo(N-1,S,Sum)
	end;

%complejidad: N^2
primo(_,_,Sum) -> Sum.

%complejidad: 1
primoaux(N,R,X) -> if
	X > R -> true;
	N rem X == 0 -> false;
	true -> primoaux(N,R,X+1)
end.