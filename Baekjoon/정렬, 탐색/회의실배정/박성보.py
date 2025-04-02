### 문제 정보 ###
# 문제 번호: 1931
# 문제 이름: 회의실 배정
# 문제 링크: https://www.acmicpc.net/problem/1931

### 문제 풀이 ###
# 1. 회의 시간 리스트를 다음 우선순위로 정렬: list[1], list[0]
# 2. count, end의 초기값을 0으로 설정
## * count는 회의 개수
## * end는 앞 회의의 종료 시간
# 3. 리스트를 모두 반복복

n = int(input())

meetings = []
for _ in range(n):
    meetings.append(list(map(int, input().split(" "))))

meetings.sort(key=lambda x: (x[1], x[0]))

count = 0
end = 0
for i in range(n):
    if meetings[i][0] >= end:
        end = meetings[i][1]
        count += 1
    else:
        continue

print(count)