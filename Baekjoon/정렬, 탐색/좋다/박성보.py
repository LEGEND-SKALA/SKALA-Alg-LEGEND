n = int(input())
nums = list(map(int, input().split(" ")))

nums.sort()
tmp = set(nums)

count = 0
for i in range(n):
    for j in range(i+1, n):
        if nums[i] + nums[j] in tmp:
            tmp.remove(nums[i] + nums[j])
            count += 1

print(count)