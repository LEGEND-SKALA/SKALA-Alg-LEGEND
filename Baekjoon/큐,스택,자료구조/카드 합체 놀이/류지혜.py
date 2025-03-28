import heapq

def card_union(cards, card_union_count):
    heapq.heapify(cards)
    
    for _ in range(card_union_count):
        x = heapq.heappop(cards)
        y = heapq.heappop(cards)
        new_val = x + y
        heapq.heappush(cards, new_val)
        heapq.heappush(cards, new_val)
    return sum(cards)

def __main__():
    # import sys
    # sys.stdin = open('input.txt', 'r')
    card_count, card_union_count = map(int, input().split())
    cards = list(map(int, input().split()))
    answer = card_union(cards, card_union_count)
    print(answer)

if __name__ == "__main__":
    __main__()