#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

int n, w, h, chk, an, mx;
pair<int, int> m[1002];
stack<pair<pair<int, int>, int>> st;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; for(int i = 0; i < n; ++i) cin >> m[i].first >> m[i].second, mx = max(mx, m[i].second);
    sort(m, m + n); st.push({{m[0]}, 0});

    for(int i = 1; i < n; ++i) {
        w = st.top().first.first; h = st.top().first.second; chk = st.top().second;
        if(chk) while(st.top().second && st.top().first.second < m[i].second) st.pop();
        st.push({{m[i]}, (st.top().first.second < m[i].second ? 0 : 1)});
    }

    while(st.size()) {
        w = st.top().first.first; h = st.top().first.second; chk = st.top().second; st.pop();
        if(st.empty()) break;
        an += abs(w - st.top().first.first) * min(h, st.top().first.second);
    }
    cout << an + mx;
}