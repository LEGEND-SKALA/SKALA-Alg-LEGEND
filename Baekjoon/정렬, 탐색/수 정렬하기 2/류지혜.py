import random
def quick_sort(num_list):
    if len(num_list) <= 1:
        return num_list
    
    # 무작위로 피벗을 선택합니다.
    pivot = random.choice(num_list)

    # 피벗을 기준으로 왼쪽(피벗보다 작은 값), 중앙(피벗과 같은 값), 오른쪽 그룸(피벗보다 큰 값)으로 분리한다.
    left = [x for x in num_list if x < pivot]
    middle = [x for x in num_list if x == pivot]
    right = [x for x in num_list if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

def __main__():
    import sys
    sys.stdin = open("input.txt", 'r')
    N = int(input())
    num_list = [int(input()) for _ in range(N)]

    result = quick_sort(num_list)
    for num in result:
        print(num)

if __name__ == "__main__":
    __main__()