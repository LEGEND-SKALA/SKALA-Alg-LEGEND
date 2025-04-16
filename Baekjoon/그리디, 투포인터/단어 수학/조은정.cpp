#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, an, idx, cnt[30];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // n개의 단어를 s로 입력 받기
    cin >> n; while(n--) {
        // cnt 배열의 알파벳에 해당되는 인덱스에 pow(10, s.size() - i - 1) 만큼 추가
        cin >> s; for(int i = 0; i < s.size(); ++i) cnt[s[i] - 'A'] += pow(10, s.size() - i - 1);
    }
    sort(cnt, cnt + 30, greater<>());   // 내림차순 정렬
    // 큰 원소 순으로 9부터 1까지 할당하여 an에 더하기 및 정답 출력
    for(int i = 9; i > 0; --i) an += cnt[idx++] * i; cout << an;
}