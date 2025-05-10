### 문제 정보 ###
# 문제 번호: 1260
# 문제 이름: DFS와 BFS
# 문제 링크: https://www.acmicpc.net/problem/1260

### 문제 풀이 ###
# DFS: 현재 정점에서 가장 작은 수로 이동하고, 해당 정점에서 반복
# BFS: 현재 정점에서 가장 가까운 수에 방문하고, 주변에 없으면 다른 정점으로 이동

import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split(" "))

graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(" "))

    graph[a].append(b)
    graph[b].append(a)

for i in range(n+1):
    graph[i].sort()

def dfs(graph: list, v: int, visited: list) -> None:
    if visited[v] == 0:
        print(v, end=" ")
        visited[v] = 1

        for neighbor in graph[v]:
            dfs(graph, neighbor, visited)

def bfs(graph: list, v: int, visited: list) -> None:
    queue = deque([v])
    visited[v] = 1

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if visited[neighbor] == 0:
                visited[neighbor] = 1
                queue.append(neighbor)

dfs(graph, v, [0 for _ in range(n+1)])
print()
bfs(graph, v, [0 for _ in range(n+1)])