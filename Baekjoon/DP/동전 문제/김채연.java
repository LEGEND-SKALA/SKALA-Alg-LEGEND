import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BJ_1398 {
    static long[] dp = new long[100];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        long N = 0;
        makedp();
        for (int i = 0; i < T; i++) {
            N = Long.parseLong(br.readLine());
            long result = 0L;
            while (N > 0) {
                result += dp[(int) (N % 100)];
                N /= 100;
            }
            sb.append(result).append("\n");
        }
        System.out.println(sb);
    }
    /**
     * ex) 1550
     * 1550 % 100 =>
     */

    /**
     * dp[i] = i원을 만들때 필요한 최소 동전의 갯수 1, 10, 25 100, 1000, 2500 / x 100 10000, 100000, 250000 / x 100 100씩 증가. 어떤 숫자가
     * 들어오든 x100을 한거와 최소 동전의 갯수는 같게 된다. 따라서 dp[99]까지 구해놓고, 숫자 N이 들어오면 거기에 대한 최소 동전의 갯수를 result 라고 하면 result += dp[N %
     * 100] 값을 계속해서 더하는것.. N /= 100
     */

    private static void makedp() {
        dp[0] = 0; //동전 0원을 만들기 위해선 0개가 필요함.
        for (int i = 1; i <= 99; i++) {
            if (i >= 25) { // 동전 1을 쓸 때, 동전 10을 쓸 때, 동전 25를 쓸 때
                dp[i] = Math.min(dp[i - 1] + 1, Math.min(dp[i - 25] + 1, dp[i - 10] + 1));
                continue;
            }
            if (i >= 10) {// 동전 1을 쓸 때, 동전 10을 쓸 때
                dp[i] = Math.min(dp[i - 1] + 1, dp[i - 10] + 1);
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }
}
