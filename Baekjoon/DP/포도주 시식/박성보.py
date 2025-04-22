### 문제 정보 ###
# 문제 번호: 2156
# 문제 이름: 포도주 시식
# 문제 링크: https://www.acmicpc.net/problem/2156

### 문제 풀이 ###
# 0. 리스트 정의
## wines: 각 와인잔에 담긴 와인의 양
## memo: 현재 와인잔까지의 마실 수 있는 최대값 기록
# 1. 규칙 기반 점화식 정의
## O O X → memo[i] = memo[i-3] + wines[i-2] + wines[i-1]
## O X O → memo[i] = memo[i-2] + wines[i-1]
## X O O → memo[i] = memo[i-1]
# 2. 초기값 정의
## memo[0] = 0 → 아무것도 마시지 않으면 0이 최대
## memo[1] = wines[0] → 한 잔만 존재하면 한 잔 마신 양이 최대
## memo[2] = wines[1] + wines[0] → 두 잔이 존재하면 두 잔 마신 양이 최대
# 3. 구현

import sys

n = int(sys.stdin.readline())
wines = [int(sys.stdin.readline()) for _ in range(n)]

memo = [0 for _ in range(n+1)]
for i in range(1, len(memo)):
    
    if i < 3:
        memo[i] = memo[i-1] + wines[i-1]
    
    else:
        memo[i] = memo[i-1]
        
        if memo[i-3] + wines[i-2] + wines[i-1] > memo[i]:
            memo[i] = memo[i-3] + wines[i-2] + wines[i-1]
            
        if memo[i-2] + wines[i-1] > memo[i]:
            memo[i] = memo[i-2] + wines[i-1]
        
print(memo[-1])