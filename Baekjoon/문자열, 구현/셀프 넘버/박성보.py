### 문제 정보 ###
# 4673. 셀프 넘버
# https://www.acmicpc.net/problem/4673

### 문제 풀이 ###
# 1. d(n) 함수 구현
# 2. 1부터 10000까지 숫자를 담는 리스트 생성
# 3. 리스트 내에 생성자로 만들 수 있는 수가 있다면, 제거
# 4. 남은 리스트 값 출력

# 생성자로 인해 만들어지는 수(=셀프 넘버가 아닌 수)를 구하는 함수
def kaprekar(n):
    k = n
    
    for x in str(n):
        k += int(x)
    
    return k
    
result = [i for i in range(1, 10001)]

for i in range(1, 10001):
    kar = kaprekar(i)
    
    if kar in result:
        result.remove(kar)
    else:
        continue
    
print("\n".join(map(str, result)))