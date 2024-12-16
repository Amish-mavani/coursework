from queue import PriorityQueue


def add_edge(graph, node, neighbor, cost):
    if node not in graph:
        graph[node] = []
    graph[node].append((neighbor, cost))


def a_star_search(graph, start, goal, heuristics):
    open_set = PriorityQueue()
    open_set.put((0, start))
   
    came_from = {}
    g_score = {start: 0}
   
    while not open_set.empty():
        current = open_set.get()[1]


        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]  # Return reversed path


        for neighbor, cost in graph.get(current, []):
            tentative_g_score = g_score[current] + cost
            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                g_score[neighbor] = tentative_g_score
                f_score = tentative_g_score + heuristics.get(neighbor, 0)
                open_set.put((f_score, neighbor))
                came_from[neighbor] = current


    return None  # No path found


def add_ao_edge(graph, parent, children, cost):
    if parent not in graph:
        graph[parent] = []
    graph[parent].append((children, cost))


def ao_star(graph, heuristics, start):
    solution_graph = {}


    def recur_ao_star(node):
        if node not in graph:
            return heuristics.get(node, float('inf'))
       
        if node in solution_graph:  
            return heuristics.get(node, float('inf'))
       
        min_cost = float('inf')
        best_subgraph = None


        for successors, cost in graph.get(node, []):
            current_cost = cost
            for succ in successors:
                current_cost += recur_ao_star(succ)


            if current_cost < min_cost:
                min_cost = current_cost
                best_subgraph = successors
       
        solution_graph[node] = best_subgraph if best_subgraph is not None else []


        return min_cost


    recur_ao_star(start)


    solution_set = set()


    def extract_solution_nodes(node):
        if node in solution_graph:
            solution_set.add(node)
            for child in solution_graph[node]:
                extract_solution_nodes(child)


    extract_solution_nodes(start)


    return solution_set




graph = {}


#edges (node, neighbor, cost)
add_edge(graph, 'A', 'B', 1)
add_edge(graph, 'A', 'C', 4)
add_edge(graph, 'B', 'D', 2)
add_edge(graph, 'C', 'D', 5)
add_edge(graph, 'B', 'E', 12)
add_edge(graph, 'D', 'E', 3)


heuristics = {
    'A': 7,
    'B': 6,
    'C': 2,
    'D': 1,
    'E': 0
}


path = a_star_search(graph, 'A', 'E', heuristics)
print("A* Path:", path)


ao_graph = {}


#edges (AND relation: parent, [children], cost)
add_ao_edge(ao_graph, 'A', ['B', 'C'], 1)
add_ao_edge(ao_graph, 'B', ['D'], 3)
add_ao_edge(ao_graph, 'C', ['E', 'F'], 2)
add_ao_edge(ao_graph, 'D', [], 2)  
add_ao_edge(ao_graph, 'E', [], 4)
add_ao_edge(ao_graph, 'F', [], 6)


ao_heuristics = {
    'A': 10,
    'B': 6,
    'C': 4,
    'D': 2,
    'E': 2,
    'F': 1
}


solution = ao_star(ao_graph, ao_heuristics, 'A')
print("\nAO* Solution Graph:", solution)
