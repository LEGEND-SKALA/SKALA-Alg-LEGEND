### 문제 정보 ###
# 문제 번호: 20366
# 문제 이름: 같이 눈사람 만들래?
# 문제 링크: https://www.acmicpc.net/problem/20366

n = int(input())
snows = list(map(int, input().split(" ")))

heights = set()
for i in range(n-1):
    for j in range(i+1, n):
        heights.add(snows[i] + snows[j])

heights = list(heights)
heights.sort()

min_div = 10**9
for i in range(len(heights)-1):
    if heights[i+1] - heights[i] < min_div:
        min_div = heights[i+1] - heights[i]
        
print(min_div)