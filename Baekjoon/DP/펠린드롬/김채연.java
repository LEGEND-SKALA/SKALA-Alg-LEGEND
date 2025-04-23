import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int M, N = 0;
    static int[] arr;
    static boolean[][] dp;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        StringBuilder sb = new StringBuilder();
        M = Integer.parseInt(br.readLine());
        dp = new boolean[N + 1][N + 1];

        initDp();
        checkPalindrome();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            sb.append(dp[l][r] ? 1 : 0).append("\n");
        }

        System.out.println(sb);
    }

    private static void initDp() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (Math.abs(i - j) == 1) {
                    dp[i][j] = (arr[i] == arr[j]);
                }
            }
        }
    }

    private static void checkPalindrome() {
        for (int len = 2; len < N; len++) {
            for (int start = 1; start <= N; start++) {
                if (len + start <= N) {
                    dp[start][start + len] = (arr[start] == arr[start + len]) && dp[start + 1][len + start - 1];
                }
            }
        }
    }
}