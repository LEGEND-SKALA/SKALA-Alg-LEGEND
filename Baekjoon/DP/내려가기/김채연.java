import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_2096 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] maxDp = new int[3];
        int[] minDp = new int[3];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; i++) {
            int value = Integer.parseInt(st.nextToken());
            maxDp[i] = value;
            minDp[i] = value;
        }

        for (int n = 1; n < N; n++) {
            st = new StringTokenizer(br.readLine());
            int[] num = new int[3];
            for (int i = 0; i < 3; i++) {
                num[i] = Integer.parseInt(st.nextToken());
            }

            int prevMax0 = maxDp[0];
            int prevMax1 = maxDp[1];
            int prevMax2 = maxDp[2];

            int prevMin0 = minDp[0];
            int prevMin1 = minDp[1];
            int prevMin2 = minDp[2];

            maxDp[0] = Math.max(prevMax0, prevMax1) + num[0];
            maxDp[1] = Math.max(Math.max(prevMax0, prevMax1), prevMax2) + num[1];
            maxDp[2] = Math.max(prevMax1, prevMax2) + num[2];

            minDp[0] = Math.min(prevMin0, prevMin1) + num[0];
            minDp[1] = Math.min(Math.min(prevMin0, prevMin1), prevMin2) + num[1];
            minDp[2] = Math.min(prevMin1, prevMin2) + num[2];
        }

        int maxResult = Math.max(Math.max(maxDp[0], maxDp[1]), maxDp[2]);
        int minResult = Math.min(Math.min(minDp[0], minDp[1]), minDp[2]);

        System.out.println(maxResult + " " + minResult);
    }
}