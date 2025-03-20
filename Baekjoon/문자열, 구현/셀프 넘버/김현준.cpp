#include <stdio.h>

int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;  // 각 자리수 더하기
        n /= 10;         // n을 한 자리씩 나누기
    }
    return sum;
}

int main() {
    int arr[10000] = {0};  // 배열 초기화 (0으로 설정)

    // 생성자들을 arr 배열에 표시
    for (int i = 1; i < 10000; i++) {
        int num = d(i);
        if (num < 10000) {
            arr[num] = 1;  // num이 생성자이면 1로 표시
        }
    }

    // 셀프 넘버 출력
    for (int i = 1; i < 10000; i++) {
        if (arr[i] == 0) {  // 생성자가 없는 숫자는 셀프 넘버
            printf("%d\n", i);
        }
    }

    return 0;
}
