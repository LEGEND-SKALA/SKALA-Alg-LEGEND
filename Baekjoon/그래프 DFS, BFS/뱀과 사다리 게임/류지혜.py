from collections import deque

def min_dice_throws(N, M, ladders, snakes):
    board = [i for i in range(101)]  # 1~100까지의 칸 초기화

    # 사다리 반영
    for start, end in ladders:
        board[start] = end

    # 뱀 반영
    for start, end in snakes:
        board[start] = end

    visited = [False] * 101
    queue = deque()
    queue.append((1, 0))  # 시작 칸, 주사위 횟수
    visited[1] = True

    while queue:
        position, moves = queue.popleft()

        if position == 100:
            return moves  # 도착점에 도달하면 주사위 횟수 반환

        for dice in range(1, 7):
            next_pos = position + dice
            if next_pos > 100:
                continue

            final_pos = board[next_pos]

            if not visited[final_pos]:
                visited[final_pos] = True
                queue.append((final_pos, moves + 1))  # 다음 위치와 주사위 횟수 +1 추가

# --- 입력 받기 ---
# 첫 줄: 사다리 개수 N, 뱀 개수 M
N, M = map(int, input().split())

# N줄: 사다리 정보
ladders = []
for _ in range(N):
    x, y = map(int, input().split())
    ladders.append((x, y))

# M줄: 뱀 정보
snakes = []
for _ in range(M):
    u, v = map(int, input().split())
    snakes.append((u, v))

# 결과 출력
print(min_dice_throws(N, M, ladders, snakes))
