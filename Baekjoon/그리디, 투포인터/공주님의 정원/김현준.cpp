#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,ans;
int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
vector<pair<int,int>> f;
int mtod(int m, int d) {
    int sum = 0;
    for (int i = 0; i < m - 1; i++) sum += md[i];
    return sum + d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m,d,start,end;
        cin>>m>>d;
        start=mtod(m,d);
        cin>>m>>d;
        end=mtod(m,d);
        f.push_back(make_pair(start,end));
    }
    sort(f.begin(),f.end(),[](pair<int, int>a, pair<int,int>b){return a.first<b.first;});
    int now = mtod(3, 1);     // 현재 시점: 3/1
    int end = mtod(11, 30);   // 목표 시점: 11/30
    int idx = 0, maxEnd = 0;

    while (now <= end) {
        bool found = false;
        for (; idx < n; idx++) {
            if (f[idx].first > now) break;
            if (f[idx].second > maxEnd) {
                maxEnd = f[idx].second;
                found = true;
            }
        }

        if (!found) {
            cout << 0 << '\n';
            return 0;
        }

        now = maxEnd;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
