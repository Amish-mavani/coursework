 Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
father(a,b).
father(a,c).
father(b,d).
father(b,e).
father(c,f).

/** <examples> Your example queries go here, e.g.
?- member(X, [cat, mouse]).
*/

brother(X, Y) :- father(F, X), father(F, Y), X \= Y.

cousin(X, Y) :- father(FX, X), father(FY, Y), brother(FX, FY).

grandson(X, Y) :- father(P, X), father(Y, P).

descendent(X, Y) :- father(Y, X).
descendent(X, Y) :- father(Z, X), descendent(Z, Y).
