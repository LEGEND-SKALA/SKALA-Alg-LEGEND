n, k = map(int,input().split())

from collections import deque
q = deque()
q.append(n)
MAX = 10**5
result = [0]*(MAX+1)
while q:
    now = q.popleft()
    if now == k:
        print(result[now])
        break
    for nx in (now-1,now+1,now*2):
        if 0 <= nx<=MAX and not result[nx]:
            result[nx] = result[now] +1
            q.append(nx)
            