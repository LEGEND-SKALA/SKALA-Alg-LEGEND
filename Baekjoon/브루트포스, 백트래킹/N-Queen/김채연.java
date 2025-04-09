import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N, count = 0;
    static int[] dx = {-1, -1, -1};
    static int[] dy = {-1, 0, 1};
    static boolean[][] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visited = new boolean[N][N];
        backtracking(0);
        System.out.println(count);
    }

    private static void backtracking(int depth) {
        if (depth == N) {
            count++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (canPlace(depth, i)) {
                visited[depth][i] = true;
                backtracking(depth + 1);
                visited[depth][i] = false;
            }
        }
    }

    private static boolean canPlace(int r, int c) {
        //만약 Depth(r)이 3이면 그 위에 i-1,(i=1) i-2까지만 보면됨 따라서 i=1부터 r보다 작을때까지
        for (int i = 1; i <= r; i++) {
            for (int j = 0; j < 3; j++) {
                int nr = r + dx[j] * i;
                int nc = c + dy[j] * i;
                if (nc < N && nc >= 0 && visited[nr][nc]) {
                    return false;
                }
            }
        }
        return true;
    }
}
