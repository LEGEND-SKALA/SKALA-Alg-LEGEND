#include <iostream>
#include <queue>
using namespace std;

// n: 풍선의 개수, m: 각 풍선 속 종이에 적혀져 있는 숫자 배열
int n, m[1002];
// d: 풍선의 번호를 저장하는 덱
deque<int> d;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 풍선의 개수와 종이에 적인 숫자 배열 입력 받기, 풍선의 번호를 차례대로 덱에 저장
    cin >> n; for(int i = 1; i <= n; ++i) cin >> m[i], d.push_back(i);

    // 덱이 비어있지 않을 때까지 반복
    while(1) {
        // 터트릴 풍선의 숫자인 덱의 front를 출력
        cout << d.front() << ' '; 
        // 터트릴 풍선의 종이에 적인 숫자를 n에 저장
        n = m[d.front()];
        // 터트릴 풍선을 pop
        d.pop_front();

        // 덱이 비어있을 경우 break
        if(!d.size()) break;

        // n이 양수일 경우, 1 만큼 감소시키기
        if(n > 0) --n;

        // n이 0이 아닐 때까지 반복
        while(n) {
            // n이 양수인 경우, 오른쪽으로 이동
            // - 덱 뒤에 덱의 front 삽입 및 front를 pop 
            // - n을 1 만큼 감소
            if(n > 0) d.push_back(d.front()), d.pop_front(), --n;
            // n이 음수인 경우, 왼쪽으로 이동
            // - 덱 앞에 덱의 back 삽입 및 back을 pop 
            // - n을 1 만큼 증가
            else d.push_front(d.back()), d.pop_back(), ++n;
        }
    }
}