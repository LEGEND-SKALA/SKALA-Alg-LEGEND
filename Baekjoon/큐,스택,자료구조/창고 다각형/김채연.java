import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int maxIdx, N, MAX, mid, sum = 0;
    static int[] arr = new int[1001];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            arr[idx] = value;
            if (MAX < value) {
                MAX = value;
                mid = idx;
            }
            if (maxIdx < idx) {
                maxIdx = idx;
            }
        }
        int max = arr[0];
        for (int i = 1; i < mid; i++) { //1 ~ mid 까지
            if (max < arr[i]) {
                sum += arr[i];
                max = arr[i];
            } else {
                sum += max;
            }
        }
        max = arr[maxIdx];
        for (int i = maxIdx; i >= mid + 1; i--) { //끝에서부터 ~ mid+1 까지
            if (max < arr[i]) {
                sum += arr[i];
                max = arr[i];
            } else {
                sum += max;
            }
        }
        System.out.println(sum + arr[mid]);
    }
}
