import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] line = br.readLine().toCharArray();
        StringBuilder sb = new StringBuilder();
        String key = br.readLine();
        for (char c : line) {
            if (!(c >= '0' && c <= '9')) {
                sb.append(c);
            }
        }
        System.out.print(sb.indexOf(key) >= 0 ? 1 : 0);
    }
}