import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int start = 0;
        int end = 0;
        int max = 0;
        int sum = 0;
        int[] arr = new int[101];
        for (int i = 0; i < 3; i++) {
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            max = Math.max(end, max);
            for (int j = start; j < end; j++) {
                arr[j]++;
            }
        }
        for (int i = 1; i <= max; i++) {
            int value = arr[i];
            if (arr[i] == 1) {
                sum += A * value;
            } else if (arr[i] == 2) {
                sum += B * value;
            } else if (arr[i] == 3) {
                sum += C * value;
            }
        }
        System.out.println(sum);
    }
}
