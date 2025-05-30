m,n = map(int, input().split())
box = [list(map(int,input().split())) for _ in range(n)]

from collections import deque
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
q = deque()
for i in range(n):
    for j in range(m):
        if box[i][j] == 1:
            q.append((i,j))

while q:
    x_, y_ = q.popleft()
    for i in range(4):
        nx = x_ + dx[i]
        ny = y_ + dy[i]
        if 0 <=nx < n and 0 <= ny < m:
            if box[nx][ny] == 0:
                box[nx][ny] = box[x_][y_] + 1
                q.append((nx,ny))

res = 0
for i in box:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    res = max(res,max(i))
print(res-1)