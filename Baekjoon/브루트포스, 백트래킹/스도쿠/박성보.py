### 문제 정보 ###
# 문제 번호: 2580
# 문제 이름: 스도쿠
# 문제 링크: https://www.acmicpc.net/problem/2580

### 문제 풀이 ###
# 1. 가로 줄 하나씩 비교해서 0 하나인 거 채우기
# 2. 세로 줄 하나씩 비교해서 0 하나인 거 채우기
# 3. 3x3 비교해서 0 하나인 거 채우기

table = []
for _ in range(9):
    table.append(list(map(int, input().split(" "))))
    
print("===== First Table =====")
for i in range(9):
    print(table[i])

for raw in range(9):
    if table[raw].count(0) == 1:
        table[raw][table[raw].index(0)] = 45 - sum(table[raw])
    else:
        continue

for col in range(9):
    tmp = []
    for raw in range(9):
        tmp.append(table[raw][col])
    
    if tmp.count(0) == 1:
        idx = tmp.index(0)
        table[idx][col] = 45 - sum(tmp)
    else:
        continue
    
# 3. 3x3 비교해서 0 하나인 거 채우기: 구현 실패
    
print("===== Last Table =====")
for i in range(9):
    print(table[i])