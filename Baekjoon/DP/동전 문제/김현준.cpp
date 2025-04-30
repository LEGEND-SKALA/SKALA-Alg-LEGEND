#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100];
long long solve(long long n,long long a)
{
    long long tmp= n%100;
    n/=100;
    a+=dp[tmp];
    if(n==0)
        return a;
    else
        return solve(n,a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    //동전 구성
    for(int i=0;i<100;i++)
    {
        if(i>=25)
        {
            dp[i]=min(dp[i-25]+1,dp[i-10]+1);
            dp[i]=min(dp[i],dp[i-1]+1);
        }
        else if(i>=10)
        {
            dp[i]=min(dp[i-10]+1,dp[i-1]+1);
        }
        else
        {
            dp[i]=i;
        }
    }
    //풀이
    vector<long long>pv;
    vector<long long>av;
    long long t;
    for(int i=0;i<N;i++)
    {
        cin>>t;
        pv.push_back(t);
    }
    for(int i=0;i<N;i++)
    {
        av.push_back(solve(pv[i],0));
    }
    for(int i=0;i<N;i++)
        cout << av[i] << "\n";
    return 0;
}
