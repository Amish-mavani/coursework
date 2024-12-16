% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
move(1, Source, Target, _) :-
    format('Move disk from ~w to ~w~n', [Source, Target]).

move(N, Source, Auxiliary, Target) :-
    N > 1,
    M is N - 1,
    move(M, Source, Auxiliary, Target),     
    move(1, Source, Target, _),              
    move(M, Auxiliary, Target, Source).      

/** <examples> Your example queries go here, e.g.
?- move(3, 1, 2, 3).
?- move(5, 1, 2, 3).
*/
