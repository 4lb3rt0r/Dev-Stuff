-module(pow).
-export([pow/2]).

pow(_, 0) -> 1;
pow(X, Y) when Y > 0 -> X * pow(X,Y-1).