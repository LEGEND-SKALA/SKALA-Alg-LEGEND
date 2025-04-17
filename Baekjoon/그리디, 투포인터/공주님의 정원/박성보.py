### 문제 정보 ###
# 문제 번호: 2457
# 문제 이름: 공주님의 정원
# 문제 링크: https://www.acmicpc.net/problem/2457

### 문제 풀이 ###
# 

import sys

n = int(sys.stdin.readline())

flowers = []
for _ in range(n):
    date = list(map(int, sys.stdin.readline().split(" ")))
    
    start = date[0:2]
    end = date[2:4]
    
    flowers.append([start, end])

flowers.sort(key=lambda x: (x[1][0] - x[0][0], x[1][1]- x[0][1]), reverse=True)

print(flowers)