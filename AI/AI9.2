import math


def calculate_distance(city1, city2):
    distance = math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)
    return distance


def tsp_greedy(cities):
    n = len(cities)
    visited = [False] * n
    path = [0]  
    visited[0] = True
    total_distance = 0


    current_city = 0


    for _ in range(n - 1):
        next_city = None
        min_distance = float('inf')


        for i in range(n):
            if not visited[i]:
                distance = calculate_distance(cities[current_city], cities[i])
                if distance < min_distance:
                    min_distance = distance
                    next_city = i


        path.append(next_city)
        visited[next_city] = True
        total_distance += min_distance
        current_city = next_city


    total_distance += calculate_distance(cities[current_city], cities[0])
    path.append(0)


    return path, total_distance


cities = [(0, 0),(6, 7),(2, 5),(4, 5),(3, 5),(6, 9),(3, 5),(8, 2)]


path, total_distance = tsp_greedy(cities)
print("\nMape :")
for i in range(len(cities)):
    print(f"{i}", cities[i])
print("\nPath taken:", path)
print("\nTotal distance:", total_distance)
