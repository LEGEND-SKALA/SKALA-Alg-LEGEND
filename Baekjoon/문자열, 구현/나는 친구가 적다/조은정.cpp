#include <iostream>
using namespace std;

string s, k, a;
int fail[200003];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> k; for(char c : a) if(!('0' <= c && c <= '9')) s += c;

    // Failure Function
    // - 탐색 문자열의 접두사와 접미사의 일치 부분을 계산하여 배열의 형태로 저장하는 함수
    for(int i = 1, j = 0; i < k.size(); ++i) {
        // 인덱스 j가 0보다 크고 인덱스 i에 해당하는 문자와 다들 때 동안, j를 fail[j - 1]로 갱신
        while(j > 0 && k[i] != k[j]) j = fail[j - 1];

        // 인덱스 i와 인덱스 j에 해당하는 문자와 같을 경우, j를 하나 증가하여 fail[i]에 저장
        if(k[i] == k[j]) fail[i] = ++j;
    }

    // KMP 알고리즘: 문자열 매칭 알고리즘
    for(int i = 0, j = 0; i < s.size(); ++i) {
        // 인덱스 j가 0보다 크고 인덱스 i에 해당하는 문자와 다들 때 동안, j를 fail[j - 1]로 갱신
        while(j > 0 && s[i] != k[j]) j = fail[j - 1];

        // 인덱스 i와 인덱스 j에 해당하는 문자와 같을 경우
        if(s[i] == k[j]) {
            if(j == k.size() - 1) {  // // 인덱스 j가 (k의 크기 - 1)일 경우, 문자열이 같다는 의미
                cout << 1; return 0;
            }
            else ++j;  // 아닌 경우, 인덱스 j를 1 증가
        }
    }
    cout << 0;
}