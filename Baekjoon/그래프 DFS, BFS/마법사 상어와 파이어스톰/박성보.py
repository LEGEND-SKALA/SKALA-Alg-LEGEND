### 문제 정보 ###
# 문제 번호: 20058
# 문제 이름: 마법사 상어와 파이어 스톰
# 문제 링크: https://www.acmicpc.net/problem/20058

### 문제 풀이 ###


import sys

n, q = map(int, sys.stdin.readline().split(" "))

# 1. Create 2^n * 2^n Size Grid
grid = [list(map(int, sys.stdin.readline().split(" "))) for _ in range(2**n)]

l = list(map(int, sys.stdin.readline().split(" ")))

for i in l:
    
    # 2. Split 2^l[i] * 2^l[i] Size Grid
    sub_grid = []
    start_x, start_y = 0, 0
    for j in range(i):
        tmp = []
        for k in range(i):
            tmp.append(grid[start_x+j][start_y+k])
        sub_grid.append([tmp])
