#include <iostream>
#include <map>
using namespace std;

int g, sz, dif, an;
string w, s;
map<char, int> mp;  // 문자의 개수에 대한 저장

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // g: 고고학자들이 찾고자 하는 단어 W의 길이
    // sz: 추출한 문자열 S의 길이
    // w: 고고학자들이 찾고자 하는 단어
    // s: 발굴된 벽화에서 추출한 문자열
    cin >> g >> sz >> w >> s; 
    
    // 현재 차이나는 문자의 개수 저장
    dif = g;

    // 고고학자들이 찾고자 하는 단어에 속하는 문자의 개수 증가
    for(char c : w) ++mp[c];

    // 벽화에서 추출된 문자열에 대해 슬라이딩 윈도우
    // (고정 사이즈의 윈도우가 이동하면서 윈도우 내에 있는 데이터를 이용해 문제를 풀이)
    for(int i = 0; i < sz; ++i) {
        // 빠지게 되는 문자에 대해
        // - mp에 존재하는 개수가 0 이상인 경우, dif + 1
        // - mp에 존재하는 개수가 -1 이하인 경우, dif - 1
        if(i >= g) dif += (mp[s[i - g]]++ >= 0 ? 1 : -1);

        // 추가되는 문자에 대해 처리
        // - mp에 존재하는 개수가 1 이상인 경우, dif - 1
        // - mp에 존재하는 개수가 0 이하인 경우, dif + 1
        dif += (mp[s[i]]-- > 0 ? -1 : 1);

        if(!dif) ++an;  // 차이가 0이므로, 순열이 존재하기에 정답 증가
    }

    // 정답 출력
    cout << an;
}