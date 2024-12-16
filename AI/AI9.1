from collections import deque


def is_valid_move(maze, x, y, visited):
    rows, cols = len(maze), len(maze[0])
    if 0 <= x < rows and 0 <= y < cols and not visited[x][y] and maze[x][y] == 0:
       return True, x, y


def maze_solver(maze, start, end):
    rows, cols = len(maze), len(maze[0])
    visited = [[False for _ in range(cols)] for _ in range(rows)]
   
    queue = deque([(start[0], start[1], [])])
    visited[start[0]][start[1]] = True


    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
   
    while queue:
        x, y, path = queue.popleft()
        path = path + [(x, y)]
       
        if (x, y) == end:
            return path
       
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_valid_move(maze, nx, ny, visited):
                visited[nx][ny] = True
                queue.append((nx, ny, path))
   
    return None


maze = [[0, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 0, 1, 0, 1],
        [0, 1, 0, 1, 0, 0, 0],
        [0, 1, 0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 1, 0, 1, 0]]
s = (0, 0)
e = (5, 6)


path = maze_solver(maze, s, e)
print("\nMaze :")
for i in range(len(maze)):
    print("\n", maze[i])
if path:
    print(f"\nPath found from {s} to {e}:\n", path)
else:
    print("No path found in the maze")
