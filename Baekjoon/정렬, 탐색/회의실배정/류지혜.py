def sort_room(meetings):
    # 종료 시간이 빠른 순, 종료 시간이 같다면 시작 시간이 빠른 순으로 정렬
    # 회의 종료시간이 빠를 수록, 더 많은 회의를 진행할 수 있음
    meetings.sort(key=lambda x: (x[1], x[0]))
    
    count = 0  # 선택된 회의의 개수
    end_time = 0  # 마지막으로 선택한 회의의 종료 시간
    
    # 회의 선택 (그리디 알고리즘)
    for start, end in meetings:
        if start >= end_time:
            count += 1
            end_time = end
    
    return count
    

def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')
    N = int(input())
    meetings = [tuple(map(int, input().split())) for _ in range(N)]
    answer = sort_room(meetings)
    print(answer)

if __name__ == "__main__":
    __main__()