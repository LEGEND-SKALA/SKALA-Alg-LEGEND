import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static int N, T = 0;
    static long[] dp = new long[101];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        makeDp();
        StringBuilder sb = new StringBuilder();
        for (int test = 0; test < T; test++) {
            sb.append(dp[Integer.parseInt(br.readLine())]).append("\n");
        }
        System.out.println(sb);

    }

    private static void makeDp() {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        for (int i = 4; i <= 100; i++) {
            dp[i] = dp[i - 2] + dp[i - 3];
        }
    }
}
