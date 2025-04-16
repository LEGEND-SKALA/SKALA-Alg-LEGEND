#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
int arr[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        int d=1;
        for(char c:s)
        {
            arr[c-'A']+=d;
            d*=10;
        }
    }
    sort(arr,arr+26,[](int a,int b){return a>b;});
    for(int i=9;i>=0;i--)
    {
        if(arr[9-i]==0)
            break;
        ans+=arr[9-i]*i;
    }
    cout<<ans<<"\n";
    return 0;
}
