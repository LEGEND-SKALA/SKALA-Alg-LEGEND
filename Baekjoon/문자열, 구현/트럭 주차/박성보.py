### 문제 정보 ###
# 2979. 트럭 주차
# https://www.acmicpc.net/problem/2979

### 문제 풀이
# 1. 시간 별로 주차장에 존재하는 트럭 수 리스트 생성
# 2. 시간 별 "한 대 당" 비용 계산
# 3. 총 비용 출력력

a, b, c = map(int, input().split(" "))

result = [0 for _ in range(100)]
for _ in range(3):
    start, end = map(int, input().split(" "))
    
    for i in range(start, end):
        result[i] += 1

time1 = result.count(1)
time2 = result.count(2)
time3 = result.count(3)

total_charge = a * time1 + 2 * b * time2 + 3 * c * time3

print(total_charge)