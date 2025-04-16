import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    static int N = 0;
    static long result = 0;
    static List<char[]> charList = new ArrayList<>();
    static Map<Character, Integer> table = new HashMap<>();
    static Map<Character, Long> sum = new HashMap<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            char[] line = br.readLine().toCharArray();
            charList.add(line);
            int len = line.length - 1;
            for (int j = len; j >= 0; j--) {
                char c = line[len - j];
                long value = (long) Math.pow(10, j);
                if (sum.containsKey(c)) {
                    sum.put(c, (sum.get(c) + value));
                } else {
                    sum.put(c, value);
                }
            }
        }
        List<Character> keySets = new ArrayList<>(sum.keySet());
        Collections.sort(keySets, new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                return sum.get((Character) o2).compareTo((sum.get((Character) o1)));
            }
        });
        int max = 9;
        for (Character c : keySets) {
            table.put(c, max);
            max--;
        }
        for (char[] list : charList) {
            StringBuilder val = new StringBuilder();
            for (char c : list) {
                val.append(table.get(c));
            }
            result += Long.parseLong(val.toString());
        }
        System.out.println(result);
    }
}