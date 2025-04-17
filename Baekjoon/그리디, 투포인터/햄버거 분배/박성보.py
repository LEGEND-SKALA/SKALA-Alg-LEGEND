### 문제 정보 ###
# 문제 번호: 19941
# 문제 이름: 햄버거 분배
# 문제 링크: https://www.acmicpc.net/problem/19941

### 문제 풀이 ###
# 1. 좌측 -> 우측 순서로 확인
# 2. 멀리 있는 햄버거부터 치환("H" -> "C")
# !. 우측 확인 시 가까운 햄버거부터 치환해서 예외 테스트 케이스 발생

import sys

n, k = map(int, sys.stdin.readline().split(" "))
tables = list(str(sys.stdin.readline()).rstrip())

count = 0
for i in range(len(tables)):
    
    # print()
    # print(f"{i} 번째 초기 Table: {tables}")
    # print(f"{i} 번째 초기 Count: {count}")
    
    if tables[i] == "P":
        
        if i - k < 0:
            start = 0
        else:
            start = i - k
            
        # print(f"{i} 번째 좌측 탐색 구간: {start} ~ {i}")
        # print(f"{i} 번째 좌측 탐색 결과: {tables[start:i].count("H") >= 1}")
        
        if i + k > len(tables):
            end = len(tables)
        else:
            end = i + k + 1
            
        # print(f"{i} 번째 우측 탐색 구간: {i+1} ~ {end}")
        # print(f"{i} 번째 우측 탐색 결과: {tables[i+1:end].count("H") >= 1}")

        if tables[start:i].count("H") >= 1:
            count += 1
            tables[start + tables[start:i].index("H")] = "C"
        elif tables[i+1:end].count("H") >= 1:
            count += 1
            tables[i+1 + tables[i+1:end:-1].index("H")] = "C" # 우측을 볼 땐 가까운 햄부기부터 치환해서 예외 케이스 발생
        else:
            continue
    
    else:
        continue
    
    # print(f"{i} 번째 최종 Table: {tables}")
    # print(f"{i} 번째 최종 Count: {count}")
    
print(count)