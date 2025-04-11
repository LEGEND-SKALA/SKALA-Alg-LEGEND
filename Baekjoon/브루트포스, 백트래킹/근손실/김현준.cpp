#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int num,decrease, ans=0;
struct kit{
    int value;
    bool used=0;
};
vector<kit> arr;
void cal(int index, int force){
    if(force<500)
        return;
    if(index==num)
        ans++;
    else
    {
        for(int i=0;i<num;i++)
        {
            if(!arr[i].used)
            {
                arr[i].used=1;
                cal(index+1,force-decrease+arr[i].value);
                arr[i].used=0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    cin>>decrease;
    for(int i=0;i<num;i++)
    {
        int n;
        cin >>n;
        arr.push_back(kit{n});
    }
    cal(0,500);
    cout<<ans<<"\n";

    return 0;
}
