/* Implementación de Métodos Computacionales
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 06/May/2022
Actividad: Act 5.1*/

% EJERCICIO 1
airport(mty).
airport(mex).
airport(nyc).
airport(gdl).
airport(mid).
airport(lax).
airport(dfw).
airport(hou).
airport(tij).
airport(ord).
airport(aal).
airport(abu).
airport(afa).
airport(agu).
airport(aip).
airport(bcn).
airport(mad).
airport(val).
airport(sev).
airport(gra).
airport(sea).
airport(sfo).
airport(ida).
airport(ytz).
airport(yul).
airport(yvr).
airport(lhr).
airport(cdg).
airport(fco).
airport(lin).
flight(mty, mex).
flight(mty, nyc).
flight(mty, gdl).
flight(mty, mid).
flight(mty, lax).
flight(mty, dfw).
flight(mty, hou).
flight(mty, tij).
flight(mty, ord).
flight(mty, aal).
flight(mty, abu).
flight(mty, afa).
flight(mty, agu).
flight(mty, aip).
flight(mty, bcn).
flight(mty, mad).
flight(mex, nyc).
flight(mex, gdl).
flight(mex, mid).
flight(mex, lax).
flight(mex, dfw).
flight(mex, hou).
flight(mex, tij).
flight(mex, ord).
flight(mex, aal).
flight(mex, abu).
flight(mex, afa).
flight(mex, agu).
flight(mex, aip).
flight(mex, bcn).
flight(mex, mad).
flight(mex, val).
flight(mex, sev).
flight(mex, gra).
flight(mex, sea).
flight(mex, sfo).
flight(mex, ida).
flight(nyc, gdl).
flight(nyc, mid).
flight(nyc, lax).
flight(nyc, dfw).
flight(nyc, hou).
flight(nyc, tij).
flight(nyc, ord).
flight(nyc, aal).
flight(nyc, abu).
flight(nyc, afa).
flight(nyc, agu).
flight(nyc, aip).
flight(nyc, bcn).
flight(nyc, mad).
flight(nyc, val).
flight(nyc, sev).
flight(nyc, gra).
flight(nyc, sea).
flight(nyc, sfo).
flight(nyc, ida).
flight(nyc, ytz).
flight(nyc, yul).
flight(nyc, yvr).
flight(gdl, mid).
flight(gdl, lax).
flight(gdl, dfw).
flight(gdl, hou).
flight(gdl, tij).
flight(gdl, ord).
flight(gdl, aal).
flight(gdl, abu).
flight(gdl, afa).
flight(gdl, agu).
flight(mid, lax).
flight(mid, dfw).
flight(mid, hou).
flight(mid, tij).
flight(mid, ord).
flight(lax, dfw).
flight(lax, hou).
flight(lax, tij).
flight(lax, ord).
flight(lax, aal).
flight(lax, abu).
flight(lax, afa).
flight(lax, agu).
flight(dfw, hou).
flight(dfw, tij).
flight(dfw, ord).
flight(dfw, aal).
flight(dfw, abu).
flight(dfw, afa).
flight(dfw, agu).
flight(dfw, aip).
flight(dfw, bcn).
flight(dfw, mad).
flight(dfw, val).
flight(dfw, sev).
flight(dfw, gra).
flight(dfw, sea).
flight(dfw, sfo).
flight(dfw, ida).
flight(dfw, ytz).
flight(dfw, yul).
flight(dfw, yvr).
flight(dfw, lhr).
flight(dfw, cdg).
flight(tij, ord).
flight(tij, aal).
flight(tij, abu).
flight(tij, afa).
flight(tij, agu).
flight(tij, aip).
flight(tij, bcn).
flight(tij, mad).
flight(ord, aal).
flight(ord, abu).
flight(ord, afa).
flight(ord, agu).
flight(ord, aip).
flight(ord, bcn).
flight(ord, mad).
flight(ord, val).
flight(ord, sev).
flight(aal, abu).
flight(aal, afa).
flight(aal, agu).
flight(aal, aip).
flight(aal, bcn).
flight(aal, mad).
flight(aal, val).
flight(aal, sev).
flight(aal, gra).
flight(aal, sea).
flight(aal, sfo).
flight(aal, ida).
flight(aal, ytz).
flight(aal, yul).
flight(aal, yvr).
flight(aal, lhr).
flight(abu, afa).
flight(abu, agu).
flight(abu, aip).
flight(abu, bcn).
flight(abu, mad).
flight(abu, val).
flight(abu, sev).
flight(abu, gra).
flight(abu, sea).
flight(abu, sfo).
flight(abu, ida).
flight(abu, ytz).
flight(abu, yul).
flight(abu, yvr).
flight(abu, lhr).
flight(abu, cdg).
flight(abu, fco).
flight(agu, aip).
flight(agu, bcn).
flight(aip, bcn).
flight(aip, mad).
flight(aip, val).
flight(aip, sev).
flight(aip, gra).
flight(aip, sea).
flight(aip, sfo).
flight(aip, ida).
flight(aip, ytz).
flight(aip, yul).
flight(aip, yvr).
flight(aip, lhr).
flight(bcn, mad).
flight(bcn, val).
flight(bcn, sev).
flight(bcn, gra).
flight(bcn, sea).
flight(mad, val).
flight(mad, sev).
flight(mad, gra).
flight(mad, sea).
flight(val, sev).
flight(sev, gra).
flight(sev, sea).
flight(sev, sfo).
flight(sev, ida).
flight(sev, ytz).
flight(sev, yul).
flight(sev, yvr).
flight(sev, lhr).
flight(sev, cdg).
flight(gra, sea).
flight(gra, sfo).
flight(sea, sfo).
flight(sea, ida).
flight(sea, ytz).
flight(sea, yul).
flight(sea, yvr).
flight(sea, lhr).
flight(sfo, ida).
flight(ida, ytz).
flight(ytz, yul).
flight(ytz, yvr).
flight(ytz, lhr).
flight(ytz, cdg).
flight(ytz, fco).
flight(yvr, lhr).

%regla de bidireccionalidad
flight1(X, Y) :- flight(X, Y). %la siguiente línea en un OR
% % flight1 (X, Y) :- flight (Y, X).

%regla para conexión de vuelos
hasconexion(X, Y) :- flight1(X, Y). %la siguiente línea en un OR
hasconexion(X, Y) :- flight1(X, A), flight1(A, Y). %la siguiente línea en un OR
hasconexion(X, Y) :- flight1(X, A), flight1(A, B), flight1(B, Y). %la siguiente línea en un OR
%---------------------------------------------------------------------------------------------------------------
% EJERCICIO 2

% node(a, b, c). 
% node(b, d, 0). 
% node(c, 0, 0). 

node(a, b, c).
node(b, d, 0).
node(d, 0, g).
node(g, 0, 0).
node(c, e, f).
node(e, h, i).
node(h, 0, 0).
node(i, 0, 0).
node(f, 0, 0).

% agrega = append L1+L2
agrega([],L2, L2).
agrega([H|L1],L2,[H|Z]) :- agrega(L1,L2,Z).

% nodos
postorder(0, []).
postorder(R, L) :- node(R, D, I), postorder(D,M), postorder(I, N), agrega(M, N, L1), agrega(L1, [R], L).