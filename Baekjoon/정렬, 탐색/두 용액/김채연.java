import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static long[] arr;
    static int left, right, size, al, ar = 0;
    static long MIN = Long.MAX_VALUE;
    static long sum = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new long[size];
        for (int i = 0; i < size; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);
        right = size - 1;
        while (left < right) {
            sum = arr[left] + arr[right];
            if (sum < 0) {
                valid(left, right);
                left++;
            } else if (sum > 0) {
                valid(left, right);
                right--;
            } else {
                al = left;
                ar = right;
                break;
            }
        }
        System.out.println(arr[al] + " " + arr[ar]);
    }

    private static void valid(int left, int right) {
        if ((Math.abs(MIN) > Math.abs(sum))) {
            al = left;
            ar = right;
            MIN = sum;
        }
    }
}