-module(translate).
-export([translate/1]).

translate(Word) -> case Word of
    blue -> azul;
    red -> rojo;
    yellow -> amarillo;
    black -> negro;
    orange -> naranja;
    white -> blanco;
    _ -> io:format("Undefined color. -n")
end.