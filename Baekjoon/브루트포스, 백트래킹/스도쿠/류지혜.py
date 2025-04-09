def solve_sudoku(board):
    """
    board: 9x9 리스트 (리스트의 리스트)로, 0은 빈 칸을 의미.
    스도쿠 문제를 백트래킹으로 풀고, 완성된 board를 반환한다.
    """
    # 9x10 크기의 불리언 배열 (인덱스 1~9 사용, 0번은 사용하지 않음)
    rows = [[False] * 10 for _ in range(9)]
    cols = [[False] * 10 for _ in range(9)]
    blocks = [[False] * 10 for _ in range(9)]

    # N-Queen 문제와 유사한 논리로 작성할 예정
    
    return board

import sys
sys.stdin = open('input.txt' , 'r')
sudocu = [list(map(int, input().split())) for _ in range(9)]
solved_board = solve_sudoku(sudocu)
for row in solved_board:
    print(*row)
