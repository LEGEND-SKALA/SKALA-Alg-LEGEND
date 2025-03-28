def decompress(input_string):
    # 33(562(71(9)))
    input_list = list(input_string)
    stack = [] # 괄호 블록 전의 길이를 저장하는 스택
    current_length = 0 # 현재까지 계산된 길이

    while input_list:
        ch = input_list.pop()
        if ch == ")":
            stack.append(current_length)
            current_length = 0
        elif ch == "(":
            multiplier = int(input_list.pop())
            prev_length = stack.pop() if stack else 0
            current_length = prev_length + multiplier * current_length
        else:
            current_length += 1
    
    return current_length

def __main__():
    # import sys
    # sys.stdin = open("input.txt", 'r')
    input_string = input()
    print(decompress(input_string))

if __name__ == "__main__":
    __main__()
    