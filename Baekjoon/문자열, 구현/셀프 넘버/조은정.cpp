#include <iostream>
using namespace std;

// c[10002]: 각 인덱스의 값에 대해 생성자로부터 만들어진 경우의 수
int a = 10001, b, d, c[10002];

int main() {
    while(--a) {  // 1부터 10000까지 반복문 실행
        // 각 값에 대해 생성자로써 만들 수 있는 수를 계산
        b = d = a; while(d) b += d % 10, d /= 10;

        if(b < 10001) ++c[b];  // 계산된 값에 대해 c[b] 1 증가
    }

    // c[i]값이 0인 경우 셀프 넘버
    for(int i = 1; i < 10001; ++i) if(!c[i]) cout << i << '\n';
}