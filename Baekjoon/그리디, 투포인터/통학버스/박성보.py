### 문제 정보 ###
# 문제 번호: 2513
# 문제 이름: 통학 버스
# 문제 링크: https://www.acmicpc.net/problem/2513

### 문제 풀이 ###
# 

import sys

n, k, s = map(int, sys.stdin.readline().split(" "))

houses = []
margin = 0
for _ in range(n):
    house, student = map(int, sys.stdin.readline().split(" "))
    margin += student # 태워야 할 학생
    
houses.sort(key=lambda x: abs(s-x[0]))

bus = 0 # 버스에 타고 있는 학생 수
dist = 0 # 버스가 이동한 거리
location = s # 현재 버스의 위치(초기 위치: 학교)

# 태워야 할 학생이 없을 때까지 반복
while margin > 0:
    
    # 버스에 k명이 타고 있으면
    if bus == k:
        dist += abs(location - s)
        location = s # 학교로 이동
        bus = 0 # 학생들 내림
        
    elif bus < k:
        
        for i in range(len(houses)):
            
            # 다음 집에 학생이 없으면
            if houses[i][1] == 0:
                # 들리지 않고 그 다음 집으로 이동
                continue
            
            # 다음 집에 학생이 있으면
            if houses[i][1] > 0:
                # 그 집으로 이동
                dist += abs(location - houses[i][0])
                location = houses[i][0]
                
                # 학생 한 명 씩 태우기
                for j in range(houses[i][1]):
                    
                    # 버스에 공간이 있으면 태우기
                    if bus < k:
                        bus += 1
                        houses[i][1] -= 1
                        margin -= 1
                        
                        # 주택가에 학생이 없으면 버스 떠남
                        if houses[i][1] == 0:
                            break
                    
                    # 버스에 정원이 다 차면 버스 떠남
                    elif bus == k:
                        break
                    
print(dist)