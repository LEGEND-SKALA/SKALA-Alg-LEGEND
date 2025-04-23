import java.io.BufferedReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String [] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int [][] items = new int[N+1][2];
        for(int i=1; i<N+1; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<2;j++) {
                items[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        //dp 이차원 배열 선언
        int [][] dp = new int[N+1][K+1];
        for(int i=1; i<N+1;i++) {
            for(int j=0; j<K+1;j++) { //무게가 0인경우가있음 .
                dp[i][j] = dp[i-1][j]; //현재 아이템을 사용하지 않고 이전아이템의 최대가치를 이용
                int w = items[i][0];
                int v = items[i][1];
                if(w<=j) { //현재 아이템의 무게보다 커야 쓸 수 있음.
                    dp[i][j]=Math.max(dp[i][j]
                            ,dp[i-1][j-w]+v);
                }
            }
        }
        System.out.println(dp[N][K]);
    }
}