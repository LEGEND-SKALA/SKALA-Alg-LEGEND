import sys
sys.stdin = open('input.txt', 'r')

textbook = list(input())
fix_textbook = []
keyword = input()

for letter in textbook:
    if letter.isnumeric():
        continue
    else:
        fix_textbook.append(letter)

print(''.join(fix_textbook).count(keyword))