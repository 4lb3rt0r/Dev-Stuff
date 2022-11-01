% Hechos de personas
persona(ana).
persona(pedro).
persona(alberto).
persona(luis).
persona(juan).
persona(carlos).
persona(maria).
persona(jose).
persona(andres).
persona(fausto).

% hecho 1 es amigo de 2
es_amigo(ana, pedro).
es_amigo(maria, alberto).
es_amigo(juan, luis).
es_amigo(carlos, ana).
es_amigo(pedro, maria).
es_amigo(andres, jose).
es_amigo(alberto, andres).
es_amigo(andres, fausto).

%regla de amistad, habiendo un lado existen ambos
son_amigos(X, Y) :- es_amigo(X, Y). %X es amigo de Y
% la siguiente linea actua como un OR
son_amigos(X, Y) :- es_amigo(Y, X). %Y es amigo de X

% hecho edad de las personas
edad(ana, 20).
edad(pedro, 25).
edad(alberto, 19).
edad(luis, 15).
edad(juan, 30).
edad(carlos, 11).
edad(maria, 16).
edad(jose, 9).
edad(andres, 55).
edad(fausto, 14).

% regla mayoría de edad
% la coma despues de edad(X, Y) actua como un AND
mayor_edad(X) :- edad(X, Y), Y >= 18. %X tiene edad >= 18

%regla menor edad.
% uso del NOT
menor_edad(X) :- persona(X), not(mayor_edad(X)). %X no tiene edad >= 18