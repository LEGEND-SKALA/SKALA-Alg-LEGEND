# 1. 치킨집과 집 찾기
def parse(city, N):
    chicken_shops = []
    houses = []
    for i in range(N):
        for j in range(N):
            if city[i][j] == 2:
                chicken_shops.append((i,j))
            elif city[i][j] == 1:
                houses.append((i,j))

    return chicken_shops, houses

# 2. 사전 계산: 각 집에서 각 치킨집까지의 맨해튼 거리를 미리 계산
# dist_matrix[i][j]는 i번째 집에서 j번째 치킨집까지의 거리
def calculate_chicken_distance(chickens, houses):
    dist_matrix = []
    for hx, hy in houses:
        chicken_distance = []
        for cx, cy in chickens:
            chicken_distance.append(abs(hx-cx) + abs(hy-cy))
        dist_matrix.append(chicken_distance)
    
    return dist_matrix

# 3. 최소 치킨 거리 계산
def calculate_min_chicken_distance_city(dist_matrix, M):
    from itertools import combinations

    chicken_shops_cnt = len(dist_matrix[0])
    houses_cnt = len(dist_matrix)
    min_total_distance = float('inf')

    # 모든 가능한 치킨집 M개 조합에 대해 반복한다.
    # 여기서 comb는 치킨집 인덱스들의 튜플이다.
    for comb in combinations(range(chicken_shops_cnt), M):
        total_distance = 0  # 현재 조합에 대한 도시의 누적 치킨 거리를 저장할 변수
        # 각 집마다 선택된 치킨집 조합 중 가장 가까운 치킨집까지의 거리를 찾는다.
        for i in range(houses_cnt):
            min_distance = float('inf')
            # 선택된 조합(comb)에 속한 각 치킨집에 대해
            # i번째 집과의 거리를 비교하여 최소 거리를 찾는다.
            for c in comb:
                if dist_matrix[i][c] < min_distance:
                    min_distance = dist_matrix[i][c]
            # 여기서 '각 집의 최소 거리를 바로 total_distance에 더하는 이유'는 다음과 같다.
            # 1. 문제 정의상, 한 집의 치킨 거리는 선택된 치킨집들 중 가장 가까운 치킨집과의 거리이다.
            # 2. 이렇게 계산한 최소 거리를 누적하면 전체 도시의 치킨 거리가 된다.
            # 3. 누적하는 즉시 total_distance에 더하는 방식은 조기 종료(early termination) 기법에 유리하다.
            #    - 만약 지금까지의 누적 total_distance가 이미 현재까지의 최소값(min_total_distance)보다 크다면,
            #      남은 집들에 대한 계산을 더 진행해도 결과가 개선될 수 없으므로 해당 조합의 계산을 바로 중단할 수 있다.
            total_distance += min_distance
            
            # 조기 종료: 현재 조합의 누적 치킨 거리가 이미 기존의 최소값보다 크거나 같으면,
            # 남은 집들을 계산할 필요가 없어 반복문을 중단한다.
            if total_distance >= min_total_distance:
                break

        # 모든 집에 대한 최소 거리를 계산한 후, 현재 조합의 총 치킨 거리가 이전 최소값보다 작으면 갱신한다.
        if total_distance < min_total_distance:
            min_total_distance = total_distance

    # 최적의 치킨 거리(즉, 모든 집의 치킨 거리 합의 최소값)를 출력한다.
    
    return min_total_distance


def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')

    N, M = map(int, input().split())
    city = [list(map(int, input().split())) for _ in range(N)]
    chicken_shops, houses = parse(city, N)
    dist_matrix = calculate_chicken_distance(chicken_shops, houses)
    answer = calculate_min_chicken_distance_city(dist_matrix, M)

    print(answer)


if __name__ == "__main__":
    __main__()