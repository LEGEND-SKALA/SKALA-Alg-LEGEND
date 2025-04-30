#include <iostream>
#include <vector>
using namespace std;
int n,t,m;
vector<long long> dp;
vector<int> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        q.push_back(t);
        m=max(m,t);
    }
    dp.resize(m + 1, 0);
    dp[1]=dp[2]=dp[3]=1;
    dp[4]=dp[5]=2;
    for(int i=6;i<=m;i++)
    {
        dp[i]=dp[i-1]+dp[i-5];
    }
    for(int i=0;i<q.size();i++)cout<<dp[q[i]]<<"\n";
    return 0;
}
