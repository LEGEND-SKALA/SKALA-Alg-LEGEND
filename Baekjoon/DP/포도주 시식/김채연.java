import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static int N = 0;
    static int[] dp;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1];
        dp = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        dp[0] = 0;
        dp[1] = arr[1];
        if (N == 1) {
            System.out.println(dp[1]);
            return;
        }
        dp[2] = dp[1] + arr[2];
        if (N == 2) {
            System.out.println(dp[2]);
            return;
        }
        int max = Integer.MIN_VALUE;
        for (int i = 3; i <= N; i++) {
            dp[i] = Math.max(Math.max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]),
                    Math.max(dp[i - 1], dp[i - 2] + arr[i]));
            max = Math.max(max, dp[i]);
        }
        System.out.println(max);
    }
}
