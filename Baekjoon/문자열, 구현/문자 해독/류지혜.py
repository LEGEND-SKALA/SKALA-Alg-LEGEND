import sys

def compute_target(W):
    """
    단어 W의 각 문자 빈도를 사전으로 계산합니다.
    """
    target = {}
    for ch in W:
        target[ch] = target.get(ch, 0) + 1
    return target

def compute_initial_window(S, g):
    """
    문자열 S의 처음 g개 문자(윈도우)의 빈도를 사전으로 계산합니다.
    """
    window = {}
    for i in range(g):
        ch = S[i]
        window[ch] = window.get(ch, 0) + 1
    return window

def is_match(window, target):
    """
    현재 윈도우의 사전(window)이 target 사전과 일치하는지 확인합니다.
    target에 포함된 모든 문자가 window에서 동일한 빈도를 가지면 True를 반환합니다.
    """
    for ch in target:
        if window.get(ch, 0) != target[ch]:
            return False
    return True

def find_anagram_count(W, S, g, s):
    """
    문자열 S 내에서 단어 W의 순열(애너그램)이 부분 문자열로 나타나는 경우의 수를 계산합니다.
    """
    total_count = 0
    target = compute_target(W)
    window = compute_initial_window(S, g)

    if is_match(window, target):
        total_count += 1

    # 슬라이딩 윈도우 방식으로 S 전체를 탐색
    for i in range(g, s):
        left_char = S[i - g]   # 윈도우에서 제거될 문자
        right_char = S[i]        # 새로 추가될 문자

        # 윈도우에서 left_char의 빈도를 감소
        window[left_char] = window.get(left_char, 0) - 1
        if window[left_char] == 0:
            del window[left_char]  # 깔끔하게 관리하기 위해 0이 되면 삭제

        # 윈도우에 right_char 추가
        window[right_char] = window.get(right_char, 0) + 1

        if is_match(window, target):
            total_count += 1

    return total_count

def main():
    # 첫 줄: g (W의 길이), |S| (S의 길이)
    g, s = map(int, input().split())
    W = input()
    S = input()

    result = find_anagram_count(W, S, g, s)
    print(result)

if __name__ == '__main__':
    main()
