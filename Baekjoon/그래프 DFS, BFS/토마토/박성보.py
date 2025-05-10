### 문제 정보 ###
# 문제 번호: 7576
# 문제 이름: 토마토
# 문제 링크: https://www.acmicpc.net/problem/7576

### 문제 풀이 ###
# 1. 토마토 상자를 visited 역할로 간주
## * 1: 방문함.
## * 0: 방문하지 않음.
## * -1: 방문할 수 없음.
# 2. Queue 및 Neighbor 관리를 위해 1차원 배열로 구성
## * IndexError 방지를 위해 토마토 상자 상하좌우를 -1로 Wrapping
## * 좌우의 경우, 현재 위치 +- 1로 방문
## * 상하의 경우, 현재 위치 +- (m+2)로 방문
# 3. Queue는 (1의 위치, 현재 일 수)로 관리
# 4. 모든 연산 후, 방문하지 않은 곳(0)이 존재하면 -1, 그렇지 않으면 일 수(day) 반환

import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split(" "))

tomato = [-1] * (m+2)
for _ in range(n):
    tomato += [-1] + list(map(int, sys.stdin.readline().split(" "))) + [-1]
tomato += [-1] * (m+2)

def min_day(m: int, visited: list) -> int:

    queue = deque()
    for i in range(len(tomato)):
        if tomato[i] == 1:
            queue.append((i, 0))
        else:
            continue

    while queue:
        location, day = queue.popleft()
        
        for neighbor in (location-1, location+1, location-(m+2), location+(m+2)):
            if tomato[neighbor] == 0:
                tomato[neighbor] = 1
                queue.append((neighbor, day+1))
        
    if 0 in visited:
        return -1
    else:
        return day

result = min_day(m, tomato)
print(result)