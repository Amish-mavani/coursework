% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space


% Your program goes here
% Family relationships
parent(albert, jim).
parent(albert, peter).
parent(jim, brian).
parent(john, darren).
parent(peter, lee).
parent(peter, sandra).
parent(peter, james).
parent(peter, kate).
parent(pat, kyle).
parent(brian, jenny).
parent(irene, jim).
parent(irene, peter).
parent(pat, brian).
parent(pat, darren).
parent(amanda, jenny).


% Gender facts
female(irene).
female(pat).
female(lee).
female(sandra).
female(jenny).
female(amanda).
female(kate).


male(albert).
male(jim).
male(peter).
male(brian).
male(john).
male(darren).
male(james).
male(kyle).


% Year of birth facts
yearOfBirth(irene, 1923).
yearOfBirth(pat, 1954).
yearOfBirth(lee, 1970).
yearOfBirth(sandra, 1973).
yearOfBirth(jenny, 2004).
yearOfBirth(amanda, 1979).
yearOfBirth(albert, 1926).
yearOfBirth(jim, 1949).
yearOfBirth(peter, 1945).
yearOfBirth(brian, 1974).
yearOfBirth(john, 1955).
yearOfBirth(darren, 1976).
yearOfBirth(james, 1969).
yearOfBirth(kate, 1975).
yearOfBirth(kyle, 1976).


grandparent_of(X,Y):-
   parent(X,Z),
   parent(Z,Y).


older(X,Y) :-
             yearOfBirth(X, A),
             yearOfBirth(Y, B),
             B > A.


sibling_of(X,Y):-  
parent(A,X),
parent(A,Y).


older_b(X,Y) :-
             sibling_of(X,Y)
             yearOfBirth(X, A),
             yearOfBirth(Y, B),
             B < A.


predecessors_of(X,Y):- parent_of(X,Y).
predecessors_of(X,Y):- parent_of(X,Z),
    predecessors_of(Z,Y).


sister_of(X,Y):-
    female(X),
    parent(F, Y), 
    parent(F,X),
    X \= Y.


male1(person('Barry', 'Drake')).
male1(person('Jim', 'Fried')).
female1(person('Dot', 'Kanga')).


/** <examples> Your example queries go here, e.g.
?-parent(albert,peter).
?-parent(jim,X).
?-parent(X,brian).
?-grandparent_of(X,brian). 
?-grandparent_of(irene,X). 
?- older(pat,X).
?- older(X,darren).
?- sibling_of(sandra,Y).
?- older_b(X,sandra).
?- predecessors_of(X,kyle).
?-sister_of(kate,Y).
?-parent(albert, _).
?-male1(person(_, LastName)).
?-female1(person(_, LastName)).
*/
