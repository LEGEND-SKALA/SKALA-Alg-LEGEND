### 문제 정보 ###
# 문제 번호: 2751
# 문제 이름: 수 정렬하기 2
# 문제 링크: https://www.acmicpc.net/problem/2751

### 문제 풀이 ###
# 1. sys Package를 활용하여 입력

import sys
n = int(sys.stdin.readline())

n_list = []
for _ in range(n):
    n_list.append(int(sys.stdin.readline()))

n_list.sort()

for i in range(len(n_list)):
    print(n_list[i])