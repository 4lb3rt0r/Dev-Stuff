-module(negatives).
-export([negatives/1]).

negatives([]) -> [];
negatives([X|Y]) when X > 0 -> negatives(Y);
negatives([X|Y]) when X < 0 -> [X] ++ negatives(Y).