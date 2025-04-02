import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static long sum = 0;
    static long[] arr;
    static int N, cnt;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);

        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = N - 1;
            long num = arr[i];

            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                } else if (right == i) {
                    right--;
                    continue;
                } else if (arr[left] + arr[right] > num) {
                    right--;
                } else if (arr[left] + arr[right] < num) {
                    left++;
                } else if (arr[left] + arr[right] == num) {
                    cnt++;
                    break;
                }
            }
        }
        System.out.println(cnt);
    }
}
