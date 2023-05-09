%cd("C:/Users/alber/Desktop/Alberto/Programacion/Erlang")
-module(reverse).
-export([reverse/1]).

reverse([]) -> [];
reverse([X|Y]) -> reverse(Y) ++ [X].