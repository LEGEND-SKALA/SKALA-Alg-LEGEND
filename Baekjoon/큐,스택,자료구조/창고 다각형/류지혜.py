def find_highest(bars):
    height_sort = sorted(bars, key=lambda x: x[1])
    return height_sort[-1]

def check_right(bars, highest_tuple):
    idx = bars.index(highest_tuple)
    right_bars = list(reversed(bars[:idx+1]))
    area = 0
    # (8, 10) (5, 3) (4, 6) (2, 4) (0, 8)
    for i in range(len(right_bars)-1):
        if right_bars[i][1] > right_bars[i+1][1]:
            width = right_bars[0][0] - right_bars[i+1][0]
            height = right_bars[i+1][1]
            area = width * height
        else:
            width = right_bars[i][0] - right_bars[i+1][0]
            height = right_bars[i+1][1]
            area += width * height
    return area

def check_left(bars, highest_tuple):
    idx = bars.index(highest_tuple)
    left_bars = bars[idx:]
    area = 0
    # (8, 10), (11, 4), (13, 6), (15, 8)
    for i in range(len(left_bars)-1):
        if left_bars[i][1] > left_bars[i+1][1]:
            width = left_bars[i+1][0] - left_bars[0][0]
            height = left_bars[i+1][1]
            area = width * height
        else:
            width = left_bars[i+1][0] - left_bars[i][0]
            height = left_bars[i+1][1]
            area += width * height
    return area

        

def __main__():
    import sys
    sys.stdin = open("input.txt", 'r')

    bar_num = int(input())
    bars = [tuple(map(int, input().split()) )for _ in range(bar_num)]

    bars = sorted(bars, key=lambda x: x[0])
    print(bars)
    highest_tuple = find_highest(bars)
    print(check_right(bars, highest_tuple))
    print(check_left(bars, highest_tuple))



if __name__ == "__main__":
    __main__()