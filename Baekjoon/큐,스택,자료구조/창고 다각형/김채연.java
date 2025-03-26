import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Deque<int[]> deque = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            int num = Integer.parseInt(st.nextToken());
            deque.offerLast(new int[]{i, num}); // {풍선 번호, 숫자}
        }

        StringBuilder sb = new StringBuilder();

        while (!deque.isEmpty()) {
            int[] balloon = deque.pollFirst();
            int index = balloon[0];
            int move = balloon[1];

            sb.append(index).append(" ");

            if (deque.isEmpty()) {
                break;
            }

            // 이동 횟수 조정
            if (move > 0) {
                for (int i = 0; i < move - 1; i++) {
                    deque.offerLast(deque.pollFirst());
                }
            } else {
                for (int i = 0; i < -move; i++) {
                    deque.offerFirst(deque.pollLast());
                }
            }
        }

        System.out.println(sb);
    }
}