import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    /**
     * 사다리: N , 뱀: M 총 100 칸 4 9
     */
    static int N, M = 0;
    static int MIN = Integer.MAX_VALUE;
    //    static int[][] arr = new int[101][101];
    static int[] nodes = new int[101];
    static boolean[] visited = new boolean[101];


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) { //사다리
            st = new StringTokenizer(br.readLine());
            nodes[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < M; i++) { //뱀
            st = new StringTokenizer(br.readLine());
            nodes[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
        }

        Deque<int[]> dq = new ArrayDeque<>();
        dq.add(new int[]{1, 0});

        while (!dq.isEmpty()) {
            int[] cur = dq.poll();

            int curIdx = cur[0];
            int cnt = cur[1];

            if (curIdx == 100) {
                MIN = Math.min(MIN, cnt);
                visited[curIdx] = false;
                continue;
            }
            //주사위 굴려
            for (int i = 1; i <= 6; i++) {
                int next = curIdx + i;
                if (next > 100) {
                    break;
                } else if (next == 100) {
                    MIN = Math.min(MIN, cnt + 1);
                } else if (!visited[next]) {
                    visited[next] = true;
                    if (nodes[next] != 0) {
                        dq.add(new int[]{nodes[next], cnt + 1});
                    } else {
                        dq.add(new int[]{next, cnt + 1});
                    }
                }
            }
        }
        System.out.println(MIN);
    }

    private static boolean isSnake(int idx) {
        return nodes[idx] < idx;
    }
}
