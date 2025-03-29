#include<iostream>
#include<string>
#include<stack>
using namespace std;
string str;
stack<char> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>str;
    for(char c: str)
    {
        if(c>='A'&&c<='Z')
        {
            cout<<c;
            continue;
        }
        else if(c=='(')
            st.push(c);
        else if(c==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c=='*' || c=='/')
        {
            while(!st.empty()&&(st.top()=='*' || st.top()=='/'))
            {
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c == '+' || c == '-'){
            while(!st.empty() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.push(c);   
    }      
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
