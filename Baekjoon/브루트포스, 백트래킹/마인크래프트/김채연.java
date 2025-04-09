import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int M, N, B = 0;
    static int resultTime = Integer.MAX_VALUE;
    static int resultHeight = -1;
    static int[][] ground;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); //세로
        M = Integer.parseInt(st.nextToken()); //가로
        B = Integer.parseInt(st.nextToken()); //블록수
        ground = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                ground[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int h = 0; h <= 256; h++) { //0부터 max까지 높이를 순회하면서 도달치:h
            int time = recursive(h, ground, B);
            if (time == -1) {
                continue;
            } else {
                if ((time < resultTime) || (time == resultTime && h > resultHeight)) {
                    resultTime = time;
                    resultHeight = h;
                }
            }
        }
        System.out.println(resultTime + " " + resultHeight);
    }

    private static int recursive(int h, int[][] arr, int block) {
        int time = 0;
        for (int i = 0; i < N; i++) { //순회
            for (int j = 0; j < M; j++) {
                int value = arr[i][j];
                if (h < value) {
                    int need = (value - h);
                    time += need * 2;
                    block += need;
                } else if (h > value) {
                    int need = h - value;
                    block -= need;
                    time += need;
                }
            }
        }
        return block < 0 ? -1 : time;
    }
}
