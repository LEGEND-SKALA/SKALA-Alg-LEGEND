#include <iostream>
#include <queue>
using namespace std;

// 뱀과 사다리 게임 (16928)
// https://www.acmicpc.net/problem/16928
/*
- BFS Alg.
- 시간복잡도: O(1)
- 공간복잡도: O(1)
*/
int arr[101], visited[101];
int n, m;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> m;
    for(int i=0; i<n+m; i++) {
        pair<int, int> info;
        cin >> info.first >> info.second;
        arr[info.first] = info.second;
    }
    return;
}
// 주사위를 1~6까지 굴리면서 확인
void bfs() {
    queue<int> que;
    // 1부터 시작
    que.push(1); visited[1] = 1;
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        // 1,2,3,4,5,6 순서로 더하면서 확인
        for(int i=1; i<=6; i++) {
            int next = cur + i;
            // 100을 넘거나, 방문했으면 continue
            if(next > 100 || visited[next]) continue;
            visited[next] = visited[cur] + 1;
            // 사다리가 있거나 뱀이라면
            if(arr[next]) {
                int next2 = arr[next];
                if(visited[next2]) continue;
                visited[next2] = visited[next];
                que.push(next2);
            } else {
                que.push(next);
            }
        }
    }
    cout << visited[100] - 1 << "\n";
    return;
}
int main() {
    fastIO();
    input();
    bfs();
    return 0;
}