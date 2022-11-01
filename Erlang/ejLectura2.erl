-module(ejLectura2).
-export([lee/1]).

lee(File) ->
    FileIn = File ++ "1.in",
    FileOut = File ++ "1.out",
    {ok, SIn} = file:open(FileIn, read),
    Txt = io:get_line(SIn, ''),

    List1 = string:split(Txt, " ", all),
    List1,
    {ok, SOut} = file:open(FileOut, [write]),
    io:format(SOut, "HOLA CRAYOLA!~s~n", [List1]).