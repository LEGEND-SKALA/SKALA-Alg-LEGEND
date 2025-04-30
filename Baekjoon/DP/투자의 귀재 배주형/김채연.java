import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] dp;
    static int H, Y = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        H = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());

        dp = new int[Y + 1];
        dp[0] = H;
        if (Y == 0) {
            System.out.println(dp[0]);
            return;
        }
        dp[1] = (int) (H * 1.05);
        if (Y == 1) {
            System.out.println(dp[1]);
            return;
        }
        dp[2] = (int) (dp[1] * 1.05);
        if (Y == 2) {
            System.out.println(dp[2]);
            return;
        }

        for (int i = 3; i <= Y; i++) {
            if (i >= 5) {
                dp[i] = Math.max(Math.max((int) (dp[i - 1] * 1.05), (int) (dp[i - 3] * 1.2)),
                        Math.max((int) (dp[i - 3] * 1.2), (int) (dp[i - 5] * 1.35)));

            } else if (i >= 3) {
                dp[i] = Math.max((int) (dp[i - 1] * 1.05), (int) (dp[i - 3] * 1.2));
            }
        }
        System.out.println(dp[Y]);
    }
}
