import sys
sys.stdin = open('input.txt', 'r')

S = input()
T = input()

while len(S) < len(T):
    if T[-1] == 'A':
        T = T[:-1]
    else:
        T = T[:-1]
        T = T[::-1]

if S == T:
    print(1)
else:
    print(0)