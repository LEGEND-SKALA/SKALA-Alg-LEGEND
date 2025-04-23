def main():
    import sys
    sys.stdin = open('input.txt', 'r')

    item_cnt, bag_max_weight = map(int, input().split())
    items = [tuple(map(int, input().split())) for _ in range(item_cnt)]
    dp = [[] for _ in range(item_cnt)]

    # for item, value in items:


if __name__ == "__main__":
    main()