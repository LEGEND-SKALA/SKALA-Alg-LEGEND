def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')
    input = sys.stdin.readline
    N = int(input())
    expect_list = [int(input()) for _ in range(N)]
    expect_list.sort()

    answer = 0
    for i in range(N):
        answer += abs(expect_list[i] - (i+1))
    
    print(answer)

if __name__ == "__main__":
    __main__()