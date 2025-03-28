from collections import deque
def order_student(students, student_num):
    students = deque(students)
    extra_line = []
    n = 1

    while students or extra_line:
        if students and students[0] == n:
            students.popleft()
            n += 1
        elif extra_line and n == extra_line[-1]:
            extra_line.pop()
            n += 1
        elif students:
            student = students.popleft()
            extra_line.append(student)
        else:
            break

    return "Nice" if n - 1 == student_num else "Sad"


def __main__():
    # import sys
    # sys.stdin = open('input.txt', 'r')

    student_num = int(input())
    students = list(map(int, input().split()))
    answer = order_student(students, student_num)
    print(answer)

if __name__ == "__main__" :
    __main__()