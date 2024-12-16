% Student exercise profile
:- set_prolog_flag(occurs_check, error).        % disallow cyclic terms
:- set_prolog_stack(global, limit(8 000 000)).  % limit term space (8Mb)
:- set_prolog_stack(local,  limit(2 000 000)).  % limit environment space

edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(d, g).
edge(e, h).
edge(f, i).

dfs(Start, Goal) :- 
    dfs_helper(Start, Goal, [Start]).

dfs_helper(Goal, Goal, _) :- 
    write('Found: '), write(Goal), nl.

dfs_helper(Current, Goal, Visited) :- 
    edge(Current, Next), \+ member(Next, Visited), 
    dfs_helper(Next, Goal, [Next | Visited]).

bfs(Start, Goal) :- 
    bfs_helper([[Start]], Goal).

bfs_helper([[Goal | Path] | _], Goal) :- 
    reverse([Goal | Path], Solution),
    write('Found: '), write(Solution), nl.

bfs_helper([Path | Paths], Goal) :- 
    Path = [Current | _],
    findall([Next, Current | Path], (edge(Current, Next), \+ member(Next, Path)), NewPaths),
    append(Paths, NewPaths, UpdatedPaths),
    bfs_helper(UpdatedPaths, Goal).

/** <examples> Your example queries go here, e.g.
% ?- dfs(a, g).
% ?- bfs(a, g).
*/
