### 문제 정보 ###
# 문제 번호: 1593
# 문제 이름: 문자 해독
# 문제 링크: https://www.acmicpc.net/problem/1593

### 문제 풀이 ###
# 1. collections Module의 Counter 함수를 활용하여 w와 s의 문자 및 개수 파악
# 2. w를 target으로 정의하고, w의 길이만큼 window를 만들어 Sliding
# 3. s 문자 하나를 window에 추가하고, window의 첫 번째 문자 제거 작업을 반복
# 4. window와 target이 같으면, result list에 시작 인덱스 추가
# +. 반복문을 w의 길이 인덱스부터 시작하기 때문에 처음부터 같은 경우는 별도로 처리

import sys
from collections import Counter

len_w, len_g = map(int, sys.stdin.readline().split(" "))
w = str(sys.stdin.readline().rstrip())
g = str(sys.stdin.readline().rstrip())

def decipheringLetters(w: str, g: str) -> list:
    
    result = []
    
    target_count = Counter(w)
    window_count = Counter(g[:len_w])
    
    if window_count == target_count:
        result.append(0)
        
    for i in range(len_w, len_g):
        window_count[g[i]] += 1
        window_count[g[i-len_w]] -= 1
        
        if window_count[g[i-len_w]] == 0:
            del window_count[g[i-len_w]]
            
        if window_count == target_count:
            result.append(i-len_w+1)
            
    return result

result = decipheringLetters(w, g)
print(len(result))