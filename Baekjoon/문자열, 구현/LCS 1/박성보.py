### 문제 정보 ###
# 9251. LCS
# https://www.acmicpc.net/problem/9251

### 문제 풀이 ###
# 1. 초기값을 0으로 갖는 (n+1) * (m+1) 2차원 배열 생성
# 2. 각 철자를 비교하며, 최장 길이를 누적하여 더하기
## 두 철자가 같으면 [i-1][j-1]의 값에 1을 더함.
## 두 철자가 다르면 [i-1][j], [i][j-1]의 값의 최대값을 가져옴.

s1 = str(input())
s2 = str(input())

lcs_li = [[0 for _ in range(len(s2)+1)] for _ in range(len(s1)+1)]

for i in range(len(s1)):
    for j in range(len(s2)):
        if s1[i] == s2[j]:
            lcs_li[i+1][j+1] = lcs_li[i][j] + 1
        else:
            lcs_li[i+1][j+1] = max(lcs_li[i][j+1], lcs_li[i+1][j])
            
            
print(lcs_li[-1][-1])