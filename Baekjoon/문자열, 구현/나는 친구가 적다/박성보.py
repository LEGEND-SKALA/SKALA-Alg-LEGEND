### 문제 정보 ###
# 16172. 나는 친구가 적다(Large)
# https://www.acmicpc.net/problem/16172

### 문제 풀이 ###
# 1. 문자열 S 및 문자열 K 입력
# 2. 문자열 S의 철자를 반복하여 숫자인 지 확인(method. str.isnumeric(): 숫자면 True, 아니면 False 출력)
# 3. True면 문자열 S에서 제거(=False인 것만 문자열 S에 추가)
# 4.문자열 K가 문자열 S에 속하는 지 비교하여 INT형으로 변환

s = str(input())
k = str(input())

s = "".join(text for text in s if not text.isnumeric())

print(int(k in s))