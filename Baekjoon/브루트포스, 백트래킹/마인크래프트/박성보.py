### 문제 정보 ###
# 문제 번호: 18111
# 문제 이름: 마인크래프트
# 문제 링크: https://www.acmicpc.net/problem/18111

### 문제 풀이 ###
# 고려해야 할 사항
## * 가지고 있는 블럭 개수
## * 평탄화 할 높이
## * 걸리는 시간

n, m, b = map(int, input().split(" "))

bottom = []
for i in range(n):
    bottom.append(list(map(int, input().split(" "))))
    
print(bottom)