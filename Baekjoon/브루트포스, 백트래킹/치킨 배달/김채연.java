import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List<int[]> houses = new ArrayList<>();
    static List<int[]> chickens = new ArrayList<>();
    static int result = Integer.MAX_VALUE;
    static int N, M = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        //치킨집과 집의 좌표 저장.
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int value = Integer.parseInt(st.nextToken());
                if (value == 1) {
                    houses.add(new int[]{i, j});
                } else if (value == 2) {
                    chickens.add(new int[]{i, j});
                }
            }
        }
        //조합 시작
        comb(0, 0, new ArrayList<>());
        System.out.println(result);

    }

    private static void comb(int start, int depth, List<int[]> selected) {
        if (depth == M) {
            int distance = getDistance(selected);
            result = Math.min(distance, result);
            return;
        }
        for (int i = start; i < chickens.size(); i++) {
            selected.add(chickens.get(i)); //치킨집 하나 골름
            comb(i + 1, depth + 1, selected);
            selected.remove(selected.size() - 1);
        }
    }

    private static int getDistance(List<int[]> selected) {
        int total = 0;
        for (int[] house : houses) {
            int min = Integer.MAX_VALUE;
            for (int[] select : selected) {
                int distance = (Math.abs(house[0] - select[0]) + Math.abs(house[1] - select[1]));
                min = Math.min(distance, min);
            }
            total += min;
        }
        return total;
    }
}
