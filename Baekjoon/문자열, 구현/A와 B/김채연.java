import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static char A = 'A';
    static char B = 'B';

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String target = br.readLine();
        String line = br.readLine();
        StringBuilder sb = new StringBuilder(line);
        while (sb.length() > target.length()) {
            if (sb.charAt(sb.length() - 1) == A) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.reverse();
                sb.deleteCharAt(0);
            }
        }
        System.out.println(sb.toString().equals(target) ? 1 : 0);
    }
}