import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N, M = 0;
    static HashMap<Integer, Boolean> mine = new HashMap<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            mine.put(Integer.parseInt(st.nextToken()), true);
        }
        StringBuilder sb = new StringBuilder();
        M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            sb.append(mine.containsKey(Integer.parseInt(st.nextToken())) ? 1 : 0).append(" ");
        }
        System.out.println(sb);
    }
}