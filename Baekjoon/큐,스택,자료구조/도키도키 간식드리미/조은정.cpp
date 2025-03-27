#include <iostream>
using namespace std;

// n: 학생 수, m: 입력 받는 학생 번호, nm: 현재 통과해야 하는 학생 번호
// st: 스택, sz: 스택의 크기
int n, m, nm = 1, st[1002], sz;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 학생 수 입력 받고, 학생 수 만큼 반복문 실행
    cin >> n; while(n--) {
        // 학생 번호 입력
        cin >> m;

        // 현재 학생 번호와 통과해야 하는 학생 번호와 같을 경우
        if(m == nm) {
            // 통과
            ++nm; 
            
            // 스택의 top과 통과해야 하는 학생 번호과 같을 동안, 통과시키기
            while(st[sz - 1] == nm) --sz, ++nm;
        }
        // 현재 학생 번호와 통과해야 하는 학생 번호가 다를 경우
        else st[sz++] = m;  // 스택에 현재 학생 번호 추가
    }

    // 스택의 top과 통과해야 하는 학생 번호과 같을 동안, 통과시키기
    while(st[sz - 1] == nm) --sz, ++nm;

    // 스택에 안에 남아 있다면 불가능한 경우, 스택이 비어있다면 가능한 경우
    cout << (sz ? "Sad" : "Nice");
}