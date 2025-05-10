### 문제 정보 ###
# 문제 번호: 13549
# 문제 이름: 숨바꼭질 3
# 문제 링크: https://www.acmicpc.net/problem/13549

### 문제 풀이 ###
# 1. n을 입력 받아서 graph 생성
## * graph는 2k+1 길이의 2차원 리스트
## * graph의 각 Index는 Node 번호를 의미하며, Value는 해당 Index와 연결된 Node를 의미
# 2. BFS를 통해 n부터 k까지의 최단 거리 계산
# 3. 순간이동의 경우, 0초가 소비되므로 가장 먼저 처리 → Queue의 가장 첫 번째 요소로 추가

import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split(" "))

def min_dist(n: int, k: int) -> int:
    
    max_range = 100000
    visited = [0] * (max_range + 1)

    queue = deque()
    queue.append((n, 0))
    visited[n] = 1

    while queue:
        location, distance = queue.popleft()

        if location == k:
            return distance
        
        for neighbor in (location-1, location+1, location*2):
            if (0 <= neighbor <= max_range) and (visited[neighbor] == 0):
                if neighbor == location*2:
                    visited[neighbor] = 1
                    queue.appendleft((neighbor, distance))
                
                elif (neighbor == location-1) or (neighbor == location+1):
                    visited[neighbor] = 1
                    queue.append((neighbor, distance+1))
                
    return -1

result = min_dist(n, k)
print(result)