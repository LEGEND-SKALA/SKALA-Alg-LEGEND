#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int num_arr, num, num_h, num_c, ans=INT_MAX;
struct Home{
    int x;
    int y;
};
struct Chiken{
    int x;
    int y;
    bool selected = 0;
};
vector<Home> arr_h;
vector<Chiken> arr_c;
void Calculate(){
    int sum=0;
    for(int i=0;i<arr_h.size();i++)
    {
        int min_d=101;
        int d=101;
        for(int j=0;j<arr_c.size();j++)
        {
            if(arr_c[j].selected)
            {
                d = abs(arr_h[i].x-arr_c[j].x)+abs(arr_h[i].y-arr_c[j].y);
                min_d=min(min_d,d);
            }
        }
        sum+=min_d;
        if(sum>ans)
            return;
    }
    ans=min(ans,sum);
}
void Select(int count, int start){
    if(count==num)
    {
        Calculate();
        return;
    }
    for(int i=start;i<arr_c.size();i++)
    {
        if(arr_c[i].selected)
            continue;
        else
        {
            arr_c[i].selected=1;
            Select(count+1,i+1);
            arr_c[i].selected=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num_arr;
    cin>>num;
    for(int i=0;i<num_arr;i++)
        for(int j=0;j<num_arr;j++)
        {
            int input;
            cin >>input;
            if(input==1)
                arr_h.push_back({i,j});
            else if(input==2)
                arr_c.push_back({i,j});
        }
    Select(0,0);
    cout<<ans<<"\n";

    return 0;
}
