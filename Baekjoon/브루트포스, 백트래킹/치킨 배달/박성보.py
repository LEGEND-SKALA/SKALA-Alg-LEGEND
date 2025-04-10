### 문제 정보 ###
# 문제 번호: 15686
# 문제 이름: 치킨 배달
# 문제 링크: https://www.acmicpc.net/problem/15686

### 문제 풀이 ###
# 1. 집(house)과 치킨집(store) 위치 탐색 및 저장
# 2. 각 치킨집 기준으로 모든 집까지의 거리 계산 후, 합계가 가장 작은 것(모든 집에서 제일 가까운 치킨집)부터 정렬
# 3. 2번을 각 집을 기준으로 남아있는(m) 모든 치킨집까지의 거리로 변경
# 4. 각 집에서 치킨집을 가기까지의 최소 거리를 계산하여 반환

n, m = map(int, input().split(" "))

cities = []
for i in range(n):
    cities.append(list(map(int, input().split(" "))))
print(f"cities: {cities}")

house, store = [], []
for i in range(n):
    for j in range(n):
        if cities[i][j] == 1:
            house.append([i, j])
        elif cities[i][j] == 2:
            store.append([i, j])
        else:
            continue
print(f"house: {house}")
print(f"store: {store}")
        
distance = []
for i in range(len(store)):
    tmp = []
    for j in range(len(house)):
        tmp.append(abs(store[i][0] - house[j][0]) + abs(store[i][1] - house[j][1]))
    distance.append(tmp)
distance.sort(key=lambda x: (min(x))) # 여기 Logic을 해결해야 함.
print(f"distance: {distance}")

min_distance = []
for i in range(len(house)):
    tmp = []
    for j in range(m):
        tmp.append(distance[j][i])
    min_distance.append(tmp)
print(f"min distance: {min_distance}")

total_min = 0
for i in range(len(min_distance)):
    total_min += min(min_distance[i])

print(f"total min: {total_min}")