import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, K, cnt = 0;
    static boolean[] hamburgers;
    static List<Integer> peoples = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        hamburgers = new boolean[N + 1];

        char[] carray = br.readLine().toCharArray();
        for (int i = 0; i < carray.length; i++) {
            char c = carray[i];
            if (c == 'H') {
                hamburgers[i + 1] = true;
            } else if (c == 'P') {
                peoples.add(i + 1);
            }
        }
        for (int i = peoples.size() - 1; i >= 0; i--) {
            int peopleIdx = peoples.get(i);
            for (int k = peopleIdx + K; k >= peopleIdx - K; k--) {
                if (k>= 1 && k <= N && hamburgers[k]) {
                    hamburgers[k] = false;
                    cnt++;
                    break;
                }
            }
        }
        System.out.println(cnt);
    }
}
