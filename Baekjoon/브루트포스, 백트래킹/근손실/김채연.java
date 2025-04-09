import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main{
    static List<Integer> kits = new ArrayList<>();
    static boolean[] visited;
    static int cnt, N, K = 0;
    static int MIN = 500;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); //depth
        K = Integer.parseInt(st.nextToken()); //얼마나빠질것인지
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            kits.add(Integer.parseInt(st.nextToken()));
        }
        visited = new boolean[kits.size()];

        backtracking(0, MIN);
        System.out.println(cnt);
    }

    private static void backtracking(int depth, int value) {
        if (N == depth) {
            cnt++;
            return;
        }
        for (int i = 0; i < kits.size(); i++) {
            if (!visited[i]) {
                int nextValue = value + kits.get(i) - K;
                if (MIN <= nextValue) {
                    visited[i] = true;
                    backtracking(depth + 1, nextValue);
                    visited[i] = false;
                }
            }
        }
    }
}
