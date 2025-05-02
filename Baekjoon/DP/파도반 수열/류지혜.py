t = int(input())
t_c = [int(input()) for _ in range(t)]
l = [0]*101
l[1]=1
l[2]=1
for i in range(3,101):
    l[i] = l[i-3]+l[i-2]
for num in t_c:
    print(l[num])