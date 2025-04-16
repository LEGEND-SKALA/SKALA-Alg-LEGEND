#include<iostream>
using namespace std;
int num,dst,ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num>>dst;
    char arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }    
    for(int i=0;i<num;i++)
    {
        if(arr[i]=='P')
        {
            for(int j=i-dst;j<=i+dst;j++)
            {
                if(0<=j && j<num && arr[j]=='H')
                    {
                        arr[j]='E';
                        ans++;
                        break;
                    }
            }
        }
    }
        cout<<ans<<"\n";

    return 0;
}
