import sys
sys.stdin = open('input.txt', 'r')

# 문자열 입력 (양쪽 끝 공백 제거)
a = input().strip()
b = input().strip()

def LCS(a, b):
    m, n = len(a), len(b)
    # (m+1) x (n+1) 크기의 dp 테이블 초기화
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # dp 테이블 채우기
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    # dp[m][n]이 LCS의 길이
    return dp[m][n]

print(LCS(a, b))
