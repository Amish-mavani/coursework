import math


class Node:
    def __init__(self, value=None, children=None):
        self.value = value
        self.children = children if children else []


def alpha_beta(node, depth, alpha, beta, maximizing_player):
    if depth == 0 or not node.children:
        return node.value
    # Beta cut-off
    if maximizing_player:
        max_eval = -math.inf
        for child in node.children:
            eval = alpha_beta(child, depth - 1, alpha, beta, False)
            max_eval = max(max_eval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break  
        return max_eval
    else:
    # Alpha cut-off
        min_eval = math.inf
        for child in node.children:
            eval = alpha_beta(child, depth - 1, alpha, beta, True)
            min_eval = min(min_eval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break  
        return min_eval


class Graph:
    def __init__(self):
        self.edges = {}
    def add_edge(self, u, v):
        if u in self.edges:
            self.edges[u].append(v)
        else:
            self.edges[u] = [v]


    def dls(self, start, goal, depth):
        if start == goal:
            return True
        if depth <= 0:
            return False
        if start in self.edges:
            for neighbor in self.edges[start]:
                if self.dls(neighbor, goal, depth - 1):
                    return True
        return False


    def dfid(self, start, goal, max_depth):
        for depth in range(max_depth + 1):
            if self.dls(start, goal, depth):
                print(f"\nGoal {goal} found at depth {depth}")
                return True
        print(f"\nGoal {goal} not found within depth limit of {depth}.")
        return False


leaf_nodes = [Node(4), Node(3), Node(5), Node(0), Node(1), Node(-1), Node(0), Node(-2),Node(1), Node(10)]
level1_nodes =[ Node(children=[leaf_nodes[0], leaf_nodes[1]]),
                Node(children=[leaf_nodes[2], leaf_nodes[3]]),
                Node(children=[leaf_nodes[4], leaf_nodes[5]]),
                Node(children=[leaf_nodes[6], leaf_nodes[7]]),
                Node(children=[leaf_nodes[8], leaf_nodes[9]])]
#root = Node(children=[level1_nodes[0], level1_nodes[1], level1_nodes[2], level1_nodes[3]])
root = Node(children=level1_nodes)


print("\nRoot node:")
root_child_values = [[child.value for child in level2_node.children] for level2_node in root.children]
print(f"R: {root_child_values}")
print("\nLevel 1 nodes:")
for i, node in enumerate(level1_nodes):
    child_values = [child.value for child in node.children]
    print(f"{i + 1}: {child_values}")
print("\nLeaf nodes:")
for i, leaf in enumerate(leaf_nodes):
    print(f"{i + 1}: {leaf.value}")


result = alpha_beta(root, 3, -math.inf, math.inf, True)
print("\nOptimal value using Alpha-Beta Pruning:", result)


g = Graph()
g.add_edge('A', 'B')
g.add_edge('A', 'C')
g.add_edge('B', 'D')
g.add_edge('B', 'E')
g.add_edge('C', 'F')
g.add_edge('C', 'G')
g.add_edge('G', 'H')
g.add_edge('E', 'I')
g.add_edge('H', 'J')


print("\nfor depth = 2")
g.dfid('A', 'J', max_depth=2)
print("\nfor depth = 4")
g.dfid('A', 'J', max_depth=4)
