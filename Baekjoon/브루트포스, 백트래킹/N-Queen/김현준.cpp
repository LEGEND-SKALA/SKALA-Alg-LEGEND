#include<iostream>
using namespace std;
int arr[15];
int num, ans=0;
bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i)
            return false;
    return true;
}
void cal(int index){
    if(index==num)
    {
        ans++;
    }
    else{
        for(int i=0;i<num;i++)
        {
            arr[index]=i;
            if(check(index))
                cal(index+1);
            
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    cal(0);
    cout<<ans<<"\n";

    return 0;
}
