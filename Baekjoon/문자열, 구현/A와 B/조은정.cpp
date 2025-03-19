#include <iostream>
using namespace std;

string s, t, tmp;

void sol(string u) {
    if(u.size() == s.size()) {  // 현재 문자열의 길이와 문자열 S의 길이가 같은 경우
        if(u == s) cout << 1;
        else cout << 0;
        exit(0);  // 종료
    }
    if(u.back() == 'A') {  // 현재 문자열 u의 맨 뒤 문자가 'A'인 경우
        // 뒤에 있는 문자 A를 제거
        tmp = ""; for(int i = 0; i < u.size() - 1; ++i) tmp += u[i]; 
        sol(tmp);
    }
    else {  // 현재 문자열 u의 맨 뒤 문자가 'B'인 경우
        // 뒤에 있는 문자 B를 제거하고 뒤집기
        tmp = ""; for(int i = 0; i < u.size() - 1; ++i) tmp = u[i] + tmp;
        sol(tmp);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> t; sol(t);
}