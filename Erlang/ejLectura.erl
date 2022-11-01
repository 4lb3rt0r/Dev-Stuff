%cd("C:/Users/alber/Desktop/Alberto/Programacion/Erlang")
%io:format(os:cmd(clear)).
-module(ejLectura).
-export([lee/1]).

lee(File) ->
    {ok, S} = file:open(File, read),
    Txt = io:get_line(S, ''),
    %Txt,
    % List1 = string:split(txt, " ", all),
    % List1,
    io:format("Hola Mundo~n"),
    List2 = string:lexemes(Txt, " "),
    List2.
    % io:format("Leí: ~s~n", Txt).