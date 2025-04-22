### 문제 정보 ###
# 문제 번호: 9461
# 문제 이름: 파도반 수열
# 문제 링크: https://www.acmicpc.net/problem/9461

### 문제 풀이 ###
# 점화식: d[i] = d[i-5] + d[i-1], i > 5
# 초기값: [1, 1, 1, 2, 2]
# 1. 함수 내에서 입력 받은 리스트 복사(초기값 유지를 위함)
# 2. 5보다 작은 수를 입력 받았을 경우, 초기값 리스트에서 인덱싱하여 반환
# 3. 5보다 큰 값을 입력 받았을 경우, 입력 받은 수에서 5만큼 빼고 재귀 반복
# 3-1. 리스트에 d[i] 값을 추가하고, d[i-5] 값 pop(리스트 길이 무한 증식 방지를 위함)
# 3-2. 반복이 완료되면, 리스트의 마지막 값 반환

import sys

n = int(sys.stdin.readline())

def padoban(num: int, li: list, i: int) -> int:
    
    tmp = li.copy()
    
    if i == num - 5:
        return tmp[-1]
    
    elif num <= 5:
        return tmp[num-1]
    
    else:
        tmp.append(tmp[0] + tmp[-1])
        tmp.pop(0)
        i += 1
        return padoban(num, tmp, i)


triangles = [1, 1, 1, 2, 2]

for _ in range(n):
    num = int(sys.stdin.readline())
    result = padoban(num, triangles, 0)
    print(result)