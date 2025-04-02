n = int(input())
n_cards = list(map(int, input().split(" ")))

m = int(input())
m_cards = list(map(int, input().split(" ")))

def binary_search(n: int, li: list) -> int:
    if len(li) == 0:
        return 0
    else:
        hp = len(li) // 2
        if n == li[hp]:
            return 1
        elif n > li[hp]:
            return binary_search(n, li[hp+1:])
        else:
            return binary_search(n, li[:hp])

n_cards.sort()

for m_card in m_cards:
    print(binary_search(m_card, n_cards), end=" ")