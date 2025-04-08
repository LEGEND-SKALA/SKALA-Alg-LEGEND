def solve_n_queens(N):
    cnt = 0
    rows = [False] * N
    diagonal1 = [False] * (2 * N - 1)
    diagonal2 = [False] * (2 * N - 1)

    def backtrack(col):
        nonlocal cnt
        
        if col == N:
            cnt += 1
            return
        
        for row in range(N):
            if not rows[row] and not diagonal1[row - col + N - 1] and not diagonal2[row + col]:
                rows[row] = True
                diagonal1[row - col + N - 1] = True
                diagonal2[row + col] = True

                backtrack(col + 1)  # 재귀 호출 시 depth 증가

                rows[row] = False
                diagonal1[row - col + N - 1] = False
                diagonal2[row + col] = False
    
    backtrack(0)
    return cnt

def __main__():
    import sys
    sys.stdin = open("input.txt", 'r')

    N = int(input())
    print(solve_n_queens(N))

if __name__ == "__main__":
    __main__()
