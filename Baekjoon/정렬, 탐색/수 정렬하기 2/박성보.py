n = int(input())

result = []
for _ in range(n):
    result.append(int(input()))

result.sort()

for i in range(n):
    print(result[i])