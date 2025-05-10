### 문제 정보 ###
# 문제 번호: 16928
# 문제 이름: 뱀과 사다리 게임
# 문제 링크: https://www.acmicpc.net/problem/16928

### 문제 풀이 ###
# 1. 지도를 graph에, 방문 여부를 visited에 저장
## * 초기에는 방문 여부를 확인할 필요가 없다고 생각했는데, 최단 거리 계산을 위해서는 확인이 필수적
# 2. Queue에는 (현재 위치, 주사위를 굴린 횟수) 저장
# 3. 주사위를 굴려서 나올 수 있는 수에서 위치 저장 및 조건 분기
## * 조건 1. 사다리와 뱀이 없으면 그냥 이동
## * 조건 2. 사다리와 뱀이 있으면 타면서 이동

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split(" "))

graph = [0] * 101
for _ in range(n + m):
    u, v = map(int, sys.stdin.readline().split(" "))
    graph[u] = v
    
def min_dice(graph: list):
    
    queue = deque()
    queue.append((1, 0))
    
    visited = [0] * 101
    visited[1] = 1
    
    while queue:
        location, dice = queue.popleft()
        
        if location == 100:
            return dice
        
        for neighbor in (location+1, location+2, location+3, location+4, location+5, location+6):
            if neighbor <= 100:
                if (graph[neighbor] == 0) and (visited[neighbor] == 0):
                    visited[neighbor] = 1
                    queue.append((neighbor, dice+1))
                    
                elif (graph[neighbor] != 0) and (visited[graph[neighbor]] == 0):
                    visited[graph[neighbor]] = 1
                    queue.append((graph[neighbor], dice+1))
                
result = min_dice(graph)
print(result)