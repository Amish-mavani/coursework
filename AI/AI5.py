from collections import deque


def is_valid(state):
    F, W, G, C = state
    if (W == G and F != W):
        return False
    if (G == C and F != G):
        return False
    return True


def get_next_states(state):
    F, W, G, C = state
    next_states = []
    moves = [(not F, F, G, C),
             (not F, not F, G, C),
             (not F, W, not G, C),
             (not F, W, G, not C)]


    for new_state in moves:
        if is_valid(new_state):
            next_states.append(new_state)


    return next_states


def bfs():
    start = (0, 0, 0, 0)
    goal = (1, 1, 1, 1)
    queue = deque([(start, [])])
    visited = set()


    while queue:
        state, path = queue.popleft()
        if state in visited:
            continue
        visited.add(state)


        if state == goal:
            return path + [state]


        for next_state in get_next_states(state):
            if next_state not in visited:
                queue.append((next_state, path + [state]))


    return None


solution = bfs()
if solution:
    for step in solution:
        print(step)
else:
    print("No solution found!")
