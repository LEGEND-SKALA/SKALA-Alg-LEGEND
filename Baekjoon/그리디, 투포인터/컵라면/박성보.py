### 문제 정보 ###
# 문제 번호: 1781
# 문제 이름: 컵라면
# 문제 링크: https://www.acmicpc.net/problem/1781

### 문제 풀이 ###
# 1. 리스트 정의
## * problems: 문제 정보, [데드라인, 컵라면 개수] 형태
## * result: 시간 별 최대 컵라면 개수, 각 Index가 시간
# 2. problems 정렬(데드라인 -> 컵라면 개수)
# 3. result에 시간 별 최대 컵라면 개수 입력, 입력 후 problems는 [0, 0]으로 변경
# 4. 더 높은 데드라인이 더 많은 컵라면을 준다면, result 수정
# 5. result의 합계 반환

import sys

n = int(sys.stdin.readline())

problems = []
for _ in range(n):
    problems.append(list(map(int, sys.stdin.readline().split(" "))))   
problems.sort(key=lambda x: (x[0], x[1]))

result = [0 for _ in range(problems[-1][0])]
for i in range(len(problems)):
    
    if result[problems[i][0]-1] < problems[i][1]:
        result[problems[i][0]-1] = problems[i][1]
        problems[i] = [0, 0]
    else:
        minimum = min(result[:problems[i][0]-1]) # 반복문 내 min() 함수 사용으로 인해 런타임 에러 발생 추정
        idx = result.index(minimum)
        
        if minimum < problems[i][1]:
            result[idx] = problems[i][1]
            problems[i] = [0, 0]
        else:
            continue

# print(f"Problems: {problems}")
# print(f"Result: {result}")

print(sum(result))