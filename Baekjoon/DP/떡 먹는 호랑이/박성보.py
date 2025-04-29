### 문제 정보 ###
# 문제 번호: 2502
# 문제 이름: 떡 먹는 호랑이
# 문제 링크: https://www.acmicpc.net/problem/2502

### 문제 풀이 ###
# 1. 2차원 리스트(memo)의 초기 값을 [[1, 0], [0, 1]]로 설정하여 생성
## * 일 수에 따라 x, y, x+y, x+2y, 2x+3y, ...
# 2. n일 후, [x의 계수, y의 계수]를 계산하여 x의 계수를 a, y의 계수를 b로 설정
## * 최종 식: ax + by = k
# 3. x와 y는 항상 1 이상이어야 하므로, x' + y' = k - a - b로 식 변경
## * x = x' + 1, y = y' + 1로 두어, ax + by = a(x'+1) + b(y'+1) = ax' + by' + a + b = k로 변환할 수 있음.
## * 따라서 ax' + by' = k - a - b
# 4. 항상 a > b이므로, (1) k를 b로 나누고, (2) 그 나머지가 a로 나누어 떨어지면 그때의 x와 y를 반환하고 반복문 종료
## * 이전에 ax' + by' = k - a - b로 치환하여 진행했으므로, 식을 구한 후, x = x' + 1, y = y' + 1 계산 필요

import sys

n, k = map(int, sys.stdin.readline().split(" "))

memo = [[1, 0], [0, 1]]

for i in range(2, n):
    memo.append([memo[i-1][0] + memo[i-2][0], memo[i-1][1] + memo[i-2][1]])
    
a, b = memo[-1][0], memo[-1][1]
k -= a + b

for i in range(k//b, -1, -1):    
    
    if (k - b * i) % a == 0:
        print(((k - b * i) // a) + 1)
        print(i + 1)
        break
    
    else:
        continue