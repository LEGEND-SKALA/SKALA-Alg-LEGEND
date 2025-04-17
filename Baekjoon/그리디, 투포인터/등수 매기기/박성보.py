### 문제 정보 ###
# 문제 번호: 2012
# 문제 이름: 등수 매기기
# 문제 링크: https://www.acmicpc.net/problem/2012

### 문제 풀이 ###
# 1. ranks 리스트 입력
# 2. ranks 리스트 정렬
# 3. |ranks[인덱스] - (인덱스 + 1)|의 합계 Return

import sys

def min_dissatisfaction() -> int:

    n = int(sys.stdin.readline())
    ranks = [int(sys.stdin.readline()) for _ in range(n)]

    ranks.sort()

    minimum = 0
    for i in range(len(ranks)):
        minimum += abs(ranks[i] - (i + 1))

    return minimum

result = min_dissatisfaction()
print(result)