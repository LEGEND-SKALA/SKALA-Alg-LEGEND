def least_road(homes, bus_limit):
    answer = 0
    while homes:
        # print("학교에서 출발")
        student_cnt = 0
        cur_loc = 0
        drive_distance = 0
        while student_cnt < bus_limit and homes:
            cur_home, cur_student = homes.pop()
            # print("현재 집:", cur_home,"집에 있는 학생수", cur_student)
            if student_cnt + cur_student <= bus_limit:
                student_cnt += cur_student
                # print("전체 탑승 가능")
                # print("탑승 학생 수:", student_cnt)
            else:
                available_student = bus_limit - student_cnt
                left_student = cur_student - available_student
                homes.append((cur_home, left_student))
                student_cnt += available_student
            
            if cur_loc == 0:
                drive_distance += cur_home
            else:
                drive_distance += abs(cur_loc - cur_home)
            cur_loc = cur_home
            # print("운전거리", drive_distance, "현재 위치", cur_loc)
        answer += drive_distance
        answer += cur_loc
        # print("학교도착")
        # print("최종 운전거리", answer)
    return answer


def __main__():
    import sys
    sys.stdin = open('input.txt', 'r')
    input = sys.stdin.readline

    home_cnt, bus_limit, school_loc = map(int, input().split())
    homes_right = []
    homes_left = []
    for _ in range(home_cnt):
        loc, student_cnt = map(int, input().split())
        if (loc - school_loc) < 0:
            homes_left.append((abs(loc-school_loc) , student_cnt))
        else:
            homes_right.append((loc - school_loc, student_cnt))

    # Sort by distance, student: small -> large
    homes_right.sort(key=lambda x: (x[0], [1]))    
    homes_left.sort(key=lambda x: (x[0], [1]))

    final_answer = least_road(homes_left, bus_limit) + least_road(homes_right, bus_limit)
    print(final_answer)



if __name__ == "__main__":
    __main__()