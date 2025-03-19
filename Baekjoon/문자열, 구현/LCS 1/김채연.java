import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        int[][] dp;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] a = br.readLine().toCharArray();
        char[] b = br.readLine().toCharArray();
        int aSize = a.length;
        int bSize = b.length;
        dp = new int[aSize + 1][bSize + 1];
        for (int i = 1; i <= aSize; i++) {
            for (int j = 1; j <= bSize; j++) {
                if (a[i - 1] == b[j - 1]) {// 같으면
                    dp[i][j] = dp[i - 1][j - 1] + 1; //+1해주고
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        System.out.println(dp[aSize][bSize]);
    }
}