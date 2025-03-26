#include <iostream>
#include <stack>
using namespace std;

int sm;         // 합계를 계산해야 할 경우 사용할 변수
string s;       // 압축되지 않은 문자열
stack<int> st;  // 문자열 길이와 압축 정보를 저장할 스택

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    // 압축되지 않은 문자열을 입력 받고 순회
    cin >> s; for(int i = 0; i < s.size(); ++i) {
        // ( 일 경우, 스택에 -1 을 저장함으로써 괄호의 시작임을 명시
        if(s[i] == '(') st.push(-1);
        // ) 일 경우
        else if(s[i] == ')') {
            // 스택의 top이 ( 를 의미하는 -1이 아닐 때까지, sm에 문자열 길이 합산
            sm = 0; while(st.top() != -1) sm += st.top(), st.pop();
            // 스택에서 ( 를 pop
            st.pop();
            // 구한 문자열의 길이가 K 번 반복되므로, K 곱하기
            sm *= st.top(); st.pop();
            // 스택에 압축을 푼 문자열의 길이를 push
            st.push(sm);
        }
        // 숫자일 경우
        // 1. 현재 스택의 top이 ( 일 경우, K번 반복됨을 의미하기 위해 현재 문자에 해당하는 숫자를 저장
        // 2. 현재 스택의 top이 ( 이 아닐 경우, 문자의 길이인 1을 스택에 저장
        else st.push(i != s.size() - 1 && s[i + 1] == '(' ? s[i] - '0' : 1);
    }

    // 현재 스택에 남아있는 단어의 길이 합산하여, 압축되지 않은 문자열 길이 출력
    sm = 0; while(st.size()) sm += st.top(), st.pop(); cout << sm;
}