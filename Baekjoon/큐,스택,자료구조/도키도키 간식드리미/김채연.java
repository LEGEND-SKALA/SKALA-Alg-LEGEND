import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static Deque<Integer> stack = new ArrayDeque<>();
    static Deque<Integer> queue = new ArrayDeque<>();
    static String NICE = "Nice";
    static String SAD = "Sad";
    static int last = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        last = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            queue.offer(Integer.parseInt(st.nextToken()));
        }
        int cur = 1;
        while (!queue.isEmpty()) {
            int next = queue.peek();
            if (next == cur) {
                cur = queue.poll() + 1;
            } else if (!stack.isEmpty() && stack.peekFirst() == cur) {
                cur = stack.pollFirst() + 1;
            } else {
                stack.addFirst(queue.poll());
            }
        }
        while (!stack.isEmpty()) {
            int next = stack.peekFirst();
            if (cur != next) {
                System.out.println(SAD);
                return;
            } else {
                cur = stack.pollFirst() + 1;
            }
        }
        System.out.println(NICE);
    }
}
