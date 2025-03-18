### 문제 정보 ###
# 12904. A와 B
# https://www.acmicpc.net/problem/12904

### 문제 풀이 ###
# 문자열 S, T 입력
# 반복문 수행
## a. T와 S가 같아지면 1을 반환하고 break or T의 길이가 0이 되면 0을 반환하고 break
## b. T와 S가 다르고, T의 길이가 0이 아니라면 연산을 거꾸로 수행
### 문자열이 "A"로 끝나는 경우: T 문자열의 가장 마지막 "A"를 제거한다.
### 문자열이 "B"로 끝나는 경우: T 문자열의 가장 마지막 "B"를 제거하고, 문자열을 뒤집는다.

s = str(input())
t = str(input())

while True:
    
    if t == s:
        print(1)
        break
    
    else:
        if len(t) == 0:
            print(0)
            break
        else:
            if t[-1] == "A":
                t = t[:-1]
            elif t[-1] == "B":
                t = t[:-1]
                t = t[::-1]