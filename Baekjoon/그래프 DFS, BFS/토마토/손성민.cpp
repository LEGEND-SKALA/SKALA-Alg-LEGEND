#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 토마토 (7576)
// https://www.acmicpc.net/problem/7576
/*
- BFS Alg.
- 시간복잡도: O(nm)
- 공간복잡도: O(1)
*/

// 2차원 좌표 공간에서 {북, 동, 남, 서} 순서 탐색
// ex) 북쪽: y좌표 -1, x좌표 그대로 0
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret, arr[1004][1004], visited[1004][1004];
queue<pair<int,int>> que;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    memset(arr, -1, sizeof(arr));
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) que.push({i, j});
        }
    }
    return;
}
void bfs() {
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        visited[y][x] = 1;
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || arr[ny][nx] != 0) continue;
            // 최소 날짜 구하기 위한 로직
            arr[ny][nx] = arr[y][x] + 1;
            que.push({ny, nx});
        }
    }
}
int main() {
    fastIO();
    input();
    bfs();
    // 탐색하며 0이 존재하면 = 아직도 덜 익은 토마토가 있다면 = 모두 익지 못하는 상황이 존재
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            if(ret < arr[i][j]) ret = arr[i][j];
        }
    }
    // 현재 ret에는 마지막으로 익고 난 후의 날짜가 저장되어 -1 해줘야 함!
    cout << ret - 1 << "\n";
    return 0;
}