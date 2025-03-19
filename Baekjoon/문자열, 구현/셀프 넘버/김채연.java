public class Main {
    static int N = 10000;
    static StringBuilder sb = new StringBuilder();
    static boolean[] map = new boolean[N + 1];

    public static void main(String[] args) throws Exception {
        for (int i = 1; i <= N; i++) {
            int num = i;
            int value = num;
            while (num > 0) {
                value += (num % 10);
                num /= 10;
            }
            if (value <= N) {
                map[value] = true;
            }
        }
        for (int i = 1; i < N; i++) {
            if (!map[i]) {
                sb.append(i).append("\n");
            }
        }
        System.out.println(sb);
    }
}