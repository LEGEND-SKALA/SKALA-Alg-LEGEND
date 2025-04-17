def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')

    table_length, k = map(int, input().split())
    line = list(input())

    people = [i for i, ch in enumerate(line) if ch == 'P']
    hamburgers = [i for i, ch in enumerate(line) if ch == 'H']

    p_ptr = h_ptr = 0
    max_match = 0

    while p_ptr < len(people) and h_ptr < len(hamburgers):
        p = people[p_ptr]
        h = hamburgers[h_ptr]

        if abs(p - h) <= k:
            max_match += 1
            p_ptr += 1
            h_ptr += 1
        elif h < p - k:
            h_ptr += 1
        else:
            p_ptr += 1

    print(max_match)

if __name__ == "__main__":
    __main__()