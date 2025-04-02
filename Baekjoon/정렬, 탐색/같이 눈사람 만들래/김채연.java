import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N = 0;
    static int MIN = Integer.MAX_VALUE;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int snow1 = arr[i] + arr[j];
                int left = i + 1;
                int right = N - 1;
                while (left < right) {
                    if (left == i || left == j) {
                        left++;
                        continue;
                    } else if (right == i || right == j) {
                        right--;
                        continue;
                    }
                    int snow2 = arr[left] + arr[right];
                    if (snow1 < snow2) {
                        right--;
                    } else if (snow1 > snow2) {
                        left++;
                    }else{
                        System.out.println("0");
                        return;
                    }
                    MIN = Math.min(MIN, Math.abs(snow2 - snow1));
                }
            }
        }
        System.out.println(MIN);
    }
}