#include <iostream>
#include <vector>
using namespace std;

// 마법사 상어와 파이어스톰(20058)
// https://www.acmicpc.net/problem/20058
// DFS Alg.
// 시간복잡도: O(q * N^2)
// 공간복잡도: O(q)
const int maxN = 64;
// dfs 처리 위한 인덱싱 (북, 동, 남, 서)
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<int> v;
int n, q, num, ret;
int sizeN;
int arr[maxN + 1][maxN + 1], visited[maxN + 1][maxN + 1];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> q;
    sizeN = (1 << n);
    for(int i=0; i<sizeN; i++) {
        for(int j=0; j<sizeN; j++) {
            cin >> arr[i][j];
            // 입력받으면서 합을 구해놓기
            ret += arr[i][j];
        }
    }
    for(int i=0; i<q; i++) {
        cin >> num;
        v.push_back(num);
    }
    return;
}
// 시계방향 회전 코드
void rotateR(int y, int x, int pos) {
    int sizePos = (1 << pos);
    int tmp[sizePos][sizePos];
    for(int i=0; i<sizePos; i++) {
        for(int j=0; j<sizePos; j++) {
            tmp[j][sizePos-1-i] = arr[y+i][x+j];
        }
    }
    for(int i=0; i<sizePos; i++) {
        for(int j=0; j<sizePos; j++) {
            arr[y+i][x+j] = tmp[i][j];
        }
    }
    return;
}
// 얼음 인접한 칸 갯수 확인
bool check(int y, int x) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= sizeN || nx < 0 || nx >= sizeN) continue;
        if(arr[ny][nx] != 0) cnt++;
    }
    return (cnt < 3);
}
void dfs(int y, int x, int &cnt) {
    visited[y][x] = 1;
    cnt++;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= sizeN || nx < 0 || nx >= sizeN) continue;
        if(visited[ny][nx] || arr[ny][nx] == 0) continue;
        dfs(ny, nx, cnt);
    }
}
void solve() {
    vector<pair<int,int>> tmp;
    for(int pos : v) {
        int sizePos = (1 << pos);
        // 격자로 나누어서 시계방향 회전
        for(int i=0; i<sizeN; i+=sizePos){
            for(int j=0; j<sizeN; j+=sizePos){
                rotateR(i, j, pos);
            }
        }
        // 회전 후, 인접한 얼음 갯수 확인 -> 모아두고 나중에 한번에 처리
        for(int i=0; i<sizeN; i++) {
            for(int j=0; j<sizeN; j++) {
                if(check(i, j) && arr[i][j] != 0) {
                    tmp.push_back({i, j});
                }
            }
        }
        // 한번에 처리
        for(pair<int,int> idx : tmp) {
            arr[idx.first][idx.second] -= 1;
            ret -= 1;
        }
        tmp.clear();
    }
    // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 갯수 확인
    int maxCnt = 0;
    for(int i = 0; i < sizeN; i++) {
        for(int j = 0; j < sizeN; j++) {
            if(!visited[i][j] && arr[i][j] > 0) {
                int cnt = 0;
                dfs(i, j, cnt);
                maxCnt = max(maxCnt, cnt);
            }
        }
    }

    cout << ret << "\n" << maxCnt << "\n";
    return;
}
int main() {
    fastIO();
    input();
    solve();
    return 0;
}