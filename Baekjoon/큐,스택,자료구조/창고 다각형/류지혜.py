def scanline(bars):
    min_x = bars[0][0]
    max_x = bars[-1][0]
    length = max_x - min_x + 1

    heights = [0] * length
    for L, H in bars:
        idx = L - min_x
        heights[idx] = max(heights[idx], H) 
    
    left_max = [0] * length
    left_max[0] = heights[0]
    for x in range(1, length):
        left_max[x] = max(left_max[x-1], heights[x])

    right_max = [0] * length
    right_max[-1] = heights[-1]
    for x in range(length - 2, -1, -1):
        right_max[x] = max(right_max[x+1], heights[x])
    
    area = 0
    for x in range(length):
        area += min(left_max[x], right_max[x])
    
    return area

        

def __main__():
    import sys
    sys.stdin = open("input.txt", 'r')

    bar_num = int(input())
    bars = [tuple(map(int, input().split()) )for _ in range(bar_num)]

    bars = sorted(bars, key=lambda x: x[0])
    print(scanline(bars))

if __name__ == "__main__":
    __main__()