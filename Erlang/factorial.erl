-module(factorial).
-export([factorial/1]).

factorial(N) -> if
    N == 0 -> 1;
    N > 0 -> N * factorial(N-1);
    true -> io:format("No support for negative numbers. -n")
end.