### 문제 정보 ###
# 문제 번호: 18429
# 문제 이름: 근손실
# 문제 링크: https://www.acmicpc.net/problem/18429

### 문제 풀이 ###
# 1. 키트에서 손실량을 빼어 운동 시 남은 근육량(margins) 계산
# 2. margins 내 요소를 활용하여 나올 수 있는 순열 배열 계산
# 3. 각 순열을 순회하며 하루라도 margin이 0보다 작아지면 count X, 그렇지 않다면 count += 1
# 4. 최종 count 출력

from itertools import permutations

n, k = map(int, input().split(" "))
kits = list(map(int, input().split(" ")))

margins = [kit - k for kit in kits]

result = []
for i in permutations(margins, n):
    result.append(i)

margin = 0
count = 0
correct = 0
for i in range(len(result)):
    margin, correct = 0, 0
    for j in range(len(result[i])):
        if margin + result[i][j] < 0:
            correct = 0
            break
        else:
            margin += result[i][j]
            correct += 1
    if correct == n:
        count += 1
    else:
        continue
    
print(count)