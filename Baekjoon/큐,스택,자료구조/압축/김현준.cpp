#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string inputstr = "";
    cin>>inputstr;
    stack<int> st_int;
    for(int i=0;i<inputstr.size();i++)
    {
        if(inputstr[i]=='(')
        {
            st_int.push(-1);
        }
        else if(inputstr[i]==')')
        {
            int length=0;
            while(st_int.top()!=-1)
            {
                length+=st_int.top();
                st_int.pop();
            }
            st_int.pop();
            length*=st_int.top();
            st_int.pop();
            st_int.push(length);
        }
        else    
        {
            if(inputstr[i+1]=='('&& i<inputstr.size()-1)
                st_int.push(inputstr[i]-'0');
            else
                st_int.push(1);
        }
    }
    int ans=0;
    while(!st_int.empty())
    {
        ans+=st_int.top();
        st_int.pop();
    }
    cout <<ans<< endl;
    return 0;
}
