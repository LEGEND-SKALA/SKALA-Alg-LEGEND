import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    /**
     * 순간이동 할 경우에는 0초 후에 2*X의 위치로 이동하게 됨.
     */
    static int N, K = 0;
    static int MAX = 100001;
    static boolean[] visitied = new boolean[MAX];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Deque<int[]> dq = new ArrayDeque<>();
        dq.add(new int[]{N, 0});
        while (!dq.isEmpty()) {
            int[] curr = dq.pollFirst();
            int idx = curr[0];
            if (idx == K) {
                System.out.println(curr[1]);
                return;
            }
            if (visitied[idx]) {
                continue;
            }
            visitied[idx] = true;
            if (idx * 2 < MAX) {
                dq.addFirst(new int[]{idx * 2, curr[1]});
            }
            if (idx - 1 >= 0) {
                dq.addLast(new int[]{idx - 1, curr[1] + 1});
            }
            if (idx + 1 < MAX) {
                dq.addLast(new int[]{idx + 1, curr[1] + 1});
            }
        }
    }
}