#!pip install pycosat
import pycosat


class WumpusWorld:
    def __init__(self, size):
        self.size = size
        self.grid = [[[] for _ in range(size)] for _ in range(size)]
        self.knowledge_base = []
        self.agent_position = (0, 0)
        self.gold_found = False
        self.add_initial_knowledge()


    def add_initial_knowledge(self):
        x, y = self.agent_position
        self.add_clause(self.get_literal("P", x, y, neg=True))  # No pit
        self.add_clause(self.get_literal("W", x, y, neg=True))  # No Wumpus
        self.add_clause(self.get_literal("B", x, y, neg=True))  # No Breeze
        self.add_clause(self.get_literal("S", x, y, neg=True))  # No Stench


    def get_literal(self, symbol, x, y, neg=False):
        literal = symbol + str(x) + str(y)
        return literal if neg else literal


    def add_clause(self, *literals):
        clause = [literal for literal in literals]
        self.knowledge_base.append(clause)


    def infer(self):
        return pycosat.solve(self.knowledge_base)


    def percept(self, percepts):
        x, y = self.agent_position
        for percept, is_present in percepts.items():
            self.add_clause(self.get_literal(percept, x, y, neg=not is_present))


    def move_agent(self, new_position):
        if new_position[0] < 0 or new_position[1] < 0 or new_position[0] >= self.size or new_position[1] >= self.size:
            print("Invalid move. Out of bounds.")
            return False
        self.agent_position = new_position
        print(f"Agent moved to position {new_position}")
        return True


    def pick_up_gold(self):
        x, y = self.agent_position
        if "G" in self.grid[x][y]:
            self.gold_found = True
            print("Gold picked up!")
            return True
        print("No gold at the current position.")
        return False


    def print_grid(self):
        for row in self.grid:
            print(" | ".join(", ".join(cell) if cell else " " for cell in row))
        print()


if __name__ == "__main__":
    world = WumpusWorld(size=4)
    world.grid[0][1] = ["B"]
    world.grid[0][2] = ["P"]
    world.grid[0][3] = ["B"]
    world.grid[1][0] = ["S"]
    world.grid[1][2] = ["B"]
    world.grid[2][0] = ["W"]
    world.grid[2][1] = ["B", "S", "G"]
    world.grid[2][2] = ["P"]
    world.grid[2][3] = ["B"]
    world.grid[3][0] = ["S"]
    world.grid[3][2] = ["B"]
    world.grid[3][3] = ["P"]


    print("Initial World Grid:")
    world.print_grid()
    moves = [(2, 1)]
    for move in moves:
        if world.move_agent(move):
            percepts = {
                "B": "B" in world.grid[move[0]][move[1]],
                "S": "S" in world.grid[move[0]][move[1]],
                "G": "G" in world.grid[move[0]][move[1]]
            }
            world.percept(percepts)
            if world.pick_up_gold():
                break
    print("\nKnowledge Base:")
    for clause in world.knowledge_base:
        print(" OR ".join(clause))


    print("\nGold Found:", world.gold_found)
