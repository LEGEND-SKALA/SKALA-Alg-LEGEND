#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;

// n: 카드의 개수, m: 카드 합체하는 횟수, u: 카드에 쓰여진 숫자를 입력 받을 변수
LL n, m, u;
// q: 카드에 쓰여진 숫자를 저장하는, 최소힙/우선순위큐
priority_queue<LL, vector<LL>, greater<LL>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 카드의 개수와 카드 합체하는 횟수 입력
    cin >> n >> m; 
    // 카드에 쓰여진 숫자를 입력 받고, 우선순위큐에 push
    while(n--) cin >> u, q.push(u);

    // 카드 합체하는 횟수만큼 반복
    // - 우선순위큐에 저장된 첫번째, 두번째로 가장 작은 수를 pop 하고, 더한 값을 우선순위큐에 push
    while(m--) u = q.top(), q.pop(), u += q.top(), q.pop(), q.push(u), q.push(u);

    // 존재하는 카드에 적혀있는 숫자들의 총합을 구하고 출력
    u = 0; while(q.size()) u += q.top(), q.pop(); cout << u;
}