def keep_muscle(N, K, exercise_kit):
    cnt = 0
    muscle = 500
    used = [False] * N

    def backtrack(muscle, days):
        nonlocal cnt
        if days == N:
            cnt += 1
            return
        
        for day in range(N):
            if not used[day] and (muscle - K + exercise_kit[day]) >= 500:
                used[day] = True
                muscle -= K
                muscle += exercise_kit[day]

                backtrack(muscle, days + 1)

                used[day] = False
                muscle += K
                muscle -= exercise_kit[day]
    backtrack(muscle, 0)
    return cnt

def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')

    N, K = map(int, input().split())
    exercise_kit = list(map(int, input().split()))

    print(keep_muscle(N, K, exercise_kit))

if __name__ == "__main__":
    __main__()