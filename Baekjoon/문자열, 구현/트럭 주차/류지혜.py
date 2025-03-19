import sys
sys.stdin = open('input.txt', 'r')

A, B, C = map(int, input().split())
cost = {1: A, 2: B, 3: C}
a_start, a_end = map(int, input().split())
b_start, b_end = map(int, input().split())
c_start, c_end = map(int, input().split())

start_time = min(a_start, b_start, c_start)
end_time = max(a_end, b_end, c_end)

t = start_time
final_cost = 0
trucks = [0] * 101
cur_truck = 0
while t < end_time:
    if t == a_start:
        cur_truck += 1
    if t == b_start:
        cur_truck += 1
    if t == c_start:
        cur_truck += 1
    
    if t == a_end:
        cur_truck -= 1
    if t == b_end:
        cur_truck -= 1
    if t == c_end:
        cur_truck -= 1
    
    trucks[t] = cur_truck
    # print(t, cur_truck)
    t += 1

for c_truck in trucks:
    if c_truck != 0:
        final_cost += cost[c_truck] * c_truck

# print(trucks)
print(final_cost)