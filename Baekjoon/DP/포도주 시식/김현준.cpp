#include<iostream>
#include<vector>
using namespace std;
int n;
int arr[10001];
int ans[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<n+1;i++)cin>>arr[i];
    ans[0]=0;
    if(n>=1)ans[1]=arr[1];
    if(n>=2)ans[2]=arr[1]+arr[2];
    for(int i=3;i<n+1;i++)
    {
        ans[i] = max((ans[i-3]+arr[i-1]+arr[i]),max(ans[i-2]+arr[i],ans[i-1]));
    }
    cout<<ans[n]<<"\n";
    
    return 0;
}
