-module(factorial_1).
-export([factorial_1/1]).

factorial_1(0) -> 1;
factorial_1(N) when N > 0 -> N * factorial_1(N-1).