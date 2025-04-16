# ### 문제 정보 ###
# 문제 번호: 1339
# 문제 이름: 단어 수학
# 문제 링크: https://www.acmicpc.net/problem/1339

# ### 문제 풀이 ###
# 1. scores 딕셔너리를 생성해서 각 알파벳 별 점수 저장
# 2. 점수는 각 알파벳의 가장 큰 자리 수를 계산: 단어의 길이 - 단어 내 알파벳의 인덱스
# 3. 점수에 따라 scores 정렬 후, 9부터 0까지 value 변경
# 4. scores의 Key(알파벳)와 Value(숫자)를 기반으로 mapping하여 합계 반환

import sys
from string import ascii_uppercase

n, k, s = map(int, sys.stdin.readline().split(" "))

words = []
for _ in range(n):
    words.append(str(sys.stdin.readline().rstrip()))

# 1. scores 딕셔너리를 생성해서 각 알파벳 별 점수 저장
scores = {}
for alphabet in ascii_uppercase:
    scores[alphabet] = 0

# 2. 점수는 각 알파벳의 가장 큰 자리 수를 계산: 단어의 길이 - 단어 내 알파벳의 인덱스
for word in words:
    for alphabet in word:
        if scores[alphabet] > len(word) - word.index(alphabet):
            continue
        else:
            scores[alphabet] = len(word) - word.index(alphabet)

# 3. 점수에 따라 scores 정렬 후, 9부터 0까지 value 변경        
scores = dict(sorted(scores.items(), key=lambda x: -x[1]))
for (key, value), i in zip(scores.items(), range(9, -1, -1)):
    if value != 0:
        scores[key] = str(i)
    else:
        break

# 4. scores의 Key(알파벳)와 Value(숫자)를 기반으로 mapping하여 합계 반환
result = sum(int(''.join(scores[alphabet] for alphabet in word)) for word in words)

print(result)
