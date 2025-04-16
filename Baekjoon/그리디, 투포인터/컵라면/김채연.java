import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class 컵라면 {
    static PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {

        if (o1[0] == o2[0]) {
            return o2[1] - o2[1];
        }
        return o1[0] - o2[0];
    });

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pq.offer(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
        }
        int sum = 0;
        PriorityQueue<Integer> solved = new PriorityQueue<>();
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int deadline = cur[0];
            int ramen = cur[1];
            solved.offer(ramen);
            if (solved.size() > deadline) {
                solved.poll();
            }
        }
        for (int r : solved) {
            sum += r;
        }
        System.out.println(sum);

    }
}
