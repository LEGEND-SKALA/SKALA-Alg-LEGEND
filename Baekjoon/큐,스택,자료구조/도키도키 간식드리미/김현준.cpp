#include<iostream>
#include<stack>
using namespace std;
int len,num,cnt=1;
stack<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>len;
    while(len--)
    {
        cin>>num;
        if(num==cnt) cnt++;
        else st.push(num);
        while(!st.empty()&& st.top()==cnt)
        {
            st.pop();
            cnt++;
        }
    }
    if(st.empty())
        cout <<"Nice"<< endl;
    else
        cout<<"Sad"<<endl;
    return 0;
}
