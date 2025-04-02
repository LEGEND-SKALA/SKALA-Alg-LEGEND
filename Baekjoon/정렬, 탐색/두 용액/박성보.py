### 문제 정보 ###
# 문제 번호: 2470
# 문제 이름: 두 용액
# 문제 링크: https://www.acmicpc.net/problem/2470

### 문제 풀이 ###
# 1. 절댓값 기준 정렬
# 2. 인접한 두 값을 더하며 최소값 확인
# 3. 최소값 갱신 및 요소 추출

n = int(input())
solutions = list(map(int, input().split(" ")))

solutions.sort(key=lambda x: abs(x))

minimum = 2000000000
result = [0, 0]
for i in range(len(solutions)-1):
    
    if abs(solutions[i] + solutions[i+1]) < abs(minimum):
        minimum = solutions[i] + solutions[i+1]
        result[0], result[1] = solutions[i], solutions[i+1]
    else:
        continue

result.sort()
print(" ".join(map(str, result)))