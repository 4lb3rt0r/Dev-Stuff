-module(ejLectura3).
-export([readfile/1]).
  
 readfile(FileName) ->
  {ok, Binary} = file:read_file(FileName),
  Lines = string:tokens(erlang:binary_to_list(Binary), "\n").