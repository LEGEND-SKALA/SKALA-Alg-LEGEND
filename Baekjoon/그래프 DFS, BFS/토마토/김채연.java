import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    /**
     * @name: 토마토
     * @param: 상자 크기 나타내는 두 정수 M(가로길이), N(세로길이) 2<=M,N<=10^3 -> O(N^2)가능 1은 익은 토마토, 0은 익지 않은 토마토, -1는 토마토 없음 토마토가 익을지
     * 토마토 익는 기준: 하루에 상하좌우
     */
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] tomato;
    static int N, M, allCnt, notCnt, alreadyCnt = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        tomato = new int[N][M];

        Deque<int[]> dq = new ArrayDeque<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                int value = Integer.parseInt(st.nextToken());
                if (value != -1) {
                    allCnt++;
                    if (value == 0) { //안익은거
                        notCnt++;
                    } else if (value == 1) { //익은거
                        alreadyCnt++;
                        dq.add(new int[]{i, j}); //익은것만 영향을 줄 수 있으니까
                    }
                }
                tomato[i][j] = value;
            }
        }
        if (alreadyCnt == allCnt) { //안익은거 + 익은거 == 모든 토마토
            System.out.println(0); //이미 익어있음
            return;
        }

        int day = -1;

        while (!dq.isEmpty()) {
            int size = dq.size();
            for (int s = 0; s < size; s++) {
                int[] cur = dq.poll();
                for (int i = 0; i < 4; i++) {

                    int nx = cur[0] + dx[i];
                    int ny = cur[1] + dy[i];
                    //토마토 익히기!
                    if (isValid(nx, ny) && tomato[nx][ny] != -1 && tomato[nx][ny] == 0) {
                        tomato[nx][ny] = 1;
                        dq.add(new int[]{nx, ny});
                    }
                }
            }
            day++;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tomato[i][j] == 1) { //원래없었던거제외
                    cnt++;
                }
            }
        }
        System.out.println(cnt == allCnt ? day : -1);
    }

    private static boolean isValid(int x, int y) {
        return y >= 0 && y < M && x >= 0 && x < N;
    }
}