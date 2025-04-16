### 문제 정보 ###
# 문제 번호: 1253
# 문제 이름: 좋다
# 문제 링크: https://www.acmicpc.net/problem/1253

### 문제 풀이 ###
# 1. 리스트 정렬
# 2. 리스트의 작은 값부터 하나씩 target으로 지정
# 3. 왼쪽부터 확인 할 start, 오른쪽부터 확인 할 end 지정
# 4. start와 end 인덱스 수의 합과 target을 비교하여 범위 좁혀오기
# 5. 만약, start와 end가 target 인덱스와 같을 경우, 각각 무시하고 넘어가기

import sys

n = int(sys.stdin.readline())
n_list = list(map(int, sys.stdin.readline().split(" ")))

def countGoodNumber(li: list) -> int:
    
    li.sort()
    count = 0
    
    for i in range(len(li)):
        
        target = li[i]
        
        start, end = 0, len(li)-1
        
        while start < end:
            
            if start == i:
                start += 1
            elif end == i:
                end -= 1
            else:
                if li[start] + li[end] == target:
                    count += 1
                    break
                elif li[start] + li[end] < target:
                    start += 1
                elif li[start] + li[end] > target:
                    end -= 1
                
            # print(f"list: {li}")
            # print(f"target: {target}")
            # print(f"li[start]: {li[start]}")
            # print(f"li[end]: {li[end]}")
            # print(f"count: {count}")
            # print("=" * 30)
                
    return count

result = countGoodNumber(n_list)
print(result)