### 문제 정보 ###
# 문제 번호: 19947
# 문제 이름: 투자의 귀재 배주형
# 문제 링크: https://www.acmicpc.net/problem/19947

### 문제 풀이 ###
# 1. 투자 결과를 memo에 기록하며 비교 진행
# 2. A 방식은 이전(i-1) 값과 비교하여 큰 값 유지
# 3. B 방식은 3년 전(i-3) 값과 비교하여 큰 값 유지
# 4. C 방식은 5년 전(i-5) 값과 비교하여 큰 값 유지
# 5. 마지막 값 반환

import sys

h, y = map(int, sys.stdin.readline().split(" "))

memo = [h for _ in range(y+1)]
for i in range(1, len(memo)):
    
    if memo[i-1] * 1.05 > memo[i]:
            memo[i] = int(memo[i-1] * 1.05)
            
    if i >= 3:
        if memo[i-3] * 1.2 > memo[i]:
            memo[i] = int(memo[i-3] * 1.2)
            
    if i >= 5:
        if memo[i-5] * 1.35 > memo[i]:
            memo[i] = int(memo[i-5] * 1.35)
        
print(memo[-1])