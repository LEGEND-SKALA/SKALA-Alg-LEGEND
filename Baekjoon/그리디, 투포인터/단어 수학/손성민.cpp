#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 단어 수학(1339)
// https://www.acmicpc.net/problem/1339
// Greedy Alg.
// 시간복잡도: O(nm)
// 공간복잡도: O(n)

/*
- N개 단어로 이루어진 수학문제
- 알파벳 대문자를 0~9중 하나로 바꾸어서 N개의 수를 합하는 문제
- 같은 알파벳은 같은 숫자로
- 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안됨
- 수의 합을 최대로 만드는 프로그램
*/
vector<int> alpha(26);
vector<string> v;
string str;
int n, ret;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> str;
        v.push_back(str);
    }
    return;
}
void solve() {
    // 알파벳 배열을 만들고 아스키 코드 값으로 위치 처리
    for(int i=0; i<n; i++) {
        int len = v[i].size();
        for(int j=0; j<len; j++) {
            // 알파벳이 해당하는 배열의 위치에 pow를 사용해 값 더하기
            alpha[v[i][j] - 'A'] += pow(10, len - j - 1);
        }
    }
    // 내림차순 정렬 -> 나타나지 않은 문자의 값은 0일거임
    sort(alpha.begin(), alpha.end(), greater<int>());
    // 최대로 구할 수 있는 숫자 구하기
    for(int i=0; i<10; i++) {
        ret += alpha[i] * (9 - i);
    }
    cout << ret << "\n";
}
int main() {
    fastIO();
    input();
    solve();
    return 0;
}