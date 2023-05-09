%cd("C:/Users/alber/Desktop/Alberto/Programacion/Erlang").
-module(lec13).
-export([speak/2, run/0]).

speak(_, 0) -> done;
speak(What, N) ->
    io:format("~p~n", [What]),
    speak(What, N-1).

run() ->
    spawn(lec13, speak, ["Hello",3]),
    spawn(lec13, speak,["Bye",5]),
    spawn(lec13, speak, ["Adios",7]),
    spawn(lec13, speak,["Crayola",4]).