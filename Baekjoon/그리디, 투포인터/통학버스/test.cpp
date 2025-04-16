#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,r;
long long ans=0;
struct ap{
    int rct;
    int dst;
    int cnt;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>r;
    vector<ap> posarr;
    vector<ap> negarr;
    for(int i=0;i<n;i++)
    {
        int num;
        int cnt;
        cin>>num>>cnt;
        int dst= num-r;
        if(dst<0)
            negarr.push_back({num,abs(dst),cnt});
        else
            posarr.push_back({num,dst,cnt});
    }
    sort(negarr.begin(),negarr.end(),[](const ap &a, const ap &b){
        return a.dst<b.dst;
    });
    sort(posarr.begin(),posarr.end(),[](const ap &a, const ap &b){
        return a.dst<b.dst;
    });
    while(!negarr.empty())
    {
        int c=m;

            if(negarr.back().cnt>c)
            {
                ans+=abs(negarr.back().dst)*2;
                negarr.back().cnt-=c;
                c=0;
            }
            else
            {
                ans+=abs(negarr.back().dst)*2;
                while(c!=0&& !negarr.empty())
                {
                    if(negarr.back().cnt>c)
                    {
                        negarr.back().cnt-=c;
                        c=0;
                    }
                    else
                    {
                        c-=negarr.back().cnt;
                        negarr.pop_back();
                    }
                }
            }
    }
    while(!posarr.empty())
    {
        int c=m;

            if(posarr.back().cnt>c)
            {
                ans+=abs(posarr.back().dst)*2;
                posarr.back().cnt-=c;
                c=0;
            }
            else
            {
                ans+=abs(posarr.back().dst)*2;
                while(c!=0 && !posarr.empty())
                {
                    if(posarr.back().cnt>c)
                    {
                        posarr.back().cnt-=c;
                        c=0;
                    }
                    else
                    {
                        c-=posarr.back().cnt;
                        posarr.pop_back();
                    }
                }
            }
    }
        cout<<ans<<"\n";
    return 0;
}
