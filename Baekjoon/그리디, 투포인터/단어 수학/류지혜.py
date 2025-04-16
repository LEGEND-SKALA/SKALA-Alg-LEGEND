from collections import defaultdict
def cnt_weight(word_list):
    letter_weight = defaultdict(int)
    for word in word_list:
        length = len(word)
        for i, ch in enumerate(word):
            letter_weight[ch] += 10 ** (length-i-1)
    return letter_weight


def match_letter(letter_weight):
    # 가중치가 높은 문자대로 9~0 부녀
    sorted_letters = sorted(letter_weight.items(), key=lambda x: -x[1])
    match_letter_dict = {}
    num_list = [str(i) for i in range(10)]
    for (letter, _) in sorted_letters:
        match_letter_dict[letter] = num_list.pop()
    return match_letter_dict


def switch_letter(match_letter_dict, word_list):
    final_num_list = []
    for word in word_list:
        new_num = ""
        for l in word:
            new_num += match_letter_dict[l]
        final_num_list.append(int(new_num))
    
    return final_num_list


def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')

    N = int(input())
    word_list = [input() for _ in range(N)]
    # 우선순위는 숫자 자리가 클수록 & 횟수가 많을 수록

    letter_weight = cnt_weight(word_list)
    match_letter_dict = match_letter(letter_weight)
    answer_list = switch_letter(match_letter_dict, word_list)
    answer = sum(answer_list)
    
    print(answer)


if __name__ == "__main__":
    __main__()