% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
disease(common_cold, runny_nose).
disease(common_cold, cough).
disease(common_cold, sore_throat).
disease(common_cold, headache).
disease(measles, fever).
disease(measles, cough).
disease(measles, runny_nose).
disease(measles, rash).
disease(chickenpox, fever).
disease(chickenpox, rash).
disease(chickenpox, itchy_skin).
disease(rubella, fever).
disease(rubella, rash).
disease(rubella, swollen_glands).
disease(flu, fever).
disease(flu, cough).
disease(flu, sore_throat).
disease(flu, headache).
disease(flu, runny_nose).

diagnose(Disease, Symptom) :- disease(Disease, Symptom).

/** <examples> Your example queries go here, e.g.
?- diagnose(D, runny_nose).
*/


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

% Your program goes here
vacuum_clean([], [], 0).

vacuum_clean([1 | Rest], [0 | CleanedRest], Performance) :-
    vacuum_clean(Rest, CleanedRest, RemainingPerformance),
    Performance is RemainingPerformance + 1.  

vacuum_clean([0 | Rest], [0 | CleanedRest], Performance) :-
    vacuum_clean(Rest, CleanedRest, Performance).  


/** <examples> Your example queries go here, e.g.
?- vacuum_clean([1, 0, 1, 0, 0, 1], CleanedTiles, Performance).
*/
