%cd("C:/Users/alber/Desktop/Alberto/Programacion/Erlang").
-module(lec14).
-export([area/0]).

area() ->
    receive
        {rectangle, H, W} ->
                io:format("Área del Rectángulo: ~p~n", [H*W]),
                area();
            {circle, R} ->
                io:format("Área del Círculo: ~p~n", [3.1416*R*R]),
                area();
            _ ->
                io:format("Área desconocida"),
                area()
    end.