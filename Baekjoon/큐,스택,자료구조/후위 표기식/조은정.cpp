#include <iostream>
#include <stack>
#include <map>
using namespace std;

char tp;
string s;
stack<char> st;
map<char, int> p;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    // 중위 표기식 입력
    cin >> s;
    
    // 연산자 우선 순위 지정
    p['+'] = p['-'] = 0; p['*'] = p['/'] = 1;

    // 중위 표기식 순회
    for(char c : s) {
        // # 알파벳인 경우
        if('A' <= c && c <= 'Z') cout << c;
        // # 스택에 현재 연산자 바로 넣는 경우
        // 1. 스택이 비어있거나
        // 2. ( 이거나
        // 3. 스택의 top이 ( 이고 현재 ) 가 아닌 경우
        else if(st.empty() || c == '(' || (st.top() == '(' && c != ')')) st.push(c);
        // # ) 인 경우
        else if(c == ')') { 
            // ( 이 나올 때까지 top 출력 및 pop
            while(1) {
                tp = st.top(); st.pop();
                if(tp == '(') break; cout << tp;
            }
        }
        // # 이외의 경우에 해당되는 연산자인 경우
        else {
            // 스택이 비어있지 않고, 스택의 top이 현재 연산자의 우선순위보다 낮지 않을 때까지 반복
            while(st.size()) {
                tp = st.top(); if(tp == '(' || p[tp] < p[c]) break;
                st.pop(); cout << tp;
            }
            // 스택에 현재 연산자 넣기
            st.push(c);
        }
    }

    // 스택에 남아있는 연산자 출력
    while(st.size()) cout << st.top(), st.pop();
}