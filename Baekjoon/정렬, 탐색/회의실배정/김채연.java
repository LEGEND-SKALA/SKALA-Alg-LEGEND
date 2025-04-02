import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N = 0;
    static PriorityQueue<int[]> pq = new PriorityQueue<>(
            (o1, o2) -> {
                int s1 = o1[0];
                int s2 = o2[0];

                int e1 = o1[1];
                int e2 = o2[1];

                if (e1 == e2) {
                    return s1 - s2;
                }
                return e1 - e2;
            }
    );

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            pq.offer(new int[]{start, end});
        }
        System.out.println(count());
    }

    private static int count() {
        int count = 1;
        int[] curr = pq.poll();
        while (!pq.isEmpty()) {
            int[] next = pq.poll();
            if (curr[1] <= next[0]) {
                count++;
                curr = next;
            }
        }
        return count;
    }
}