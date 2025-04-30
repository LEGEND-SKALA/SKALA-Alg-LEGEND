import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_2502 {
    static Pair[] dp;
    static int D, K = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        dp = new Pair[D + 1];

        dp[3] = new Pair(1, 1);

        for (int i = 4; i <= D; i++) {
            if (i == 4) {
                dp[4] = new Pair(2, 1);
                continue;
            }
            dp[i] = new Pair(dp[i - 1].A + dp[i - 2].A, dp[i - 1].B + dp[i - 2].B);
        }

        int x = dp[D].A;
        int y = dp[D].B;

        for (int a = 1; a <= K; a++) {
            for (int b = 1; b <= a; b++) {
                if (x * a + y * b == K) {
                    System.out.println(b + "\n" + a);
                    return;
                }
            }
        }
    }

    private static class Pair {
        int A;
        int B;

        public Pair(int a, int b) {
            A = a;
            B = b;
        }
    }
}
