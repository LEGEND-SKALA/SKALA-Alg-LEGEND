result = [0]*10001
for i in range(10002):
    new_num = i + sum(map(int, list(str(i))))
    if new_num < 10001:
        result[new_num] = 1

for i in range(10001):
    if result[i] == 0:
        print(i)