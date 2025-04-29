### 문제 정보 ###
# 문제 번호: 1398
# 문제 이름: 동전 문제
# 문제 링크: https://www.acmicpc.net/problem/1398

### 문제 풀이 ###
# 1. 숫자의 규칙을 보니, 2자리씩 최소 동전 개수를 기록하면 될 것 같음.
## * ex. 250111 → 25 / 01 / 11
# 2. 1번을 지키며, 최소 동전 개수 기록
## a. 25원으로 나누어 떨어지는 경우: 25원 동전 개수
## b. 10원으로 나누어 떨어지는 경우: 10원 동전 개수
## c. 25원으로 나누어지는 경우: 25원 동전 개수
## d. 10원으로 나누어지는 경우: 10원 동전 개수
## e. 나머지 금액: 1원 동전 개수 

import sys

t = int(sys.stdin.readline())

for _ in range(t):

    cost = int(sys.stdin.readline())
    memo = [0]

    i = 1
    sub_cost = cost
    
    while i <= len(str(cost)) // 2 + 1:
        
        coin = 0
        sub_cost = (cost % (100 ** i)) // (100 ** (i-1))

        if sub_cost % 25 == 0:
            coin += sub_cost // 25
            sub_cost %= 25
        if sub_cost % 10 == 0:
            coin += sub_cost // 10
            sub_cost %= 10
        if sub_cost // 25 > 0:
            coin += sub_cost // 25
            sub_cost %= 25
        if sub_cost // 10 > 0:
            coin += sub_cost // 10
            sub_cost %= 10
        coin += sub_cost

        memo.append(memo[-1] + coin)
        i += 1
    
    print(memo[-1])