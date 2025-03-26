import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] line = br.readLine().toCharArray();

        Deque<Character> stack = new ArrayDeque<>();
        for (char c : line) {
            stack.addLast(c); // 순서대로 넣기
        }

        System.out.println(getLength(stack));
    }

    private static int getLength(Deque<Character> stack) {
        int len = 0;

        while (!stack.isEmpty()) {
            char cur = stack.pollFirst();

            if (cur == ')') {
                // 닫는 괄호 만나면 종료 (재귀 호출용)
                break;
            } else if (Character.isDigit(cur)) {
                if (!stack.isEmpty() && stack.peekFirst() == '(') {
                    stack.pollFirst(); // 여는 괄호 제거
                    int innerLen = getLength(stack); // 괄호 안 계산
                    len += (cur - '0') * innerLen;
                } else {
                    len++; // 그냥 숫자 하나면 길이 1로 증가
                }
            } else {
                len++; // 알파벳 등 일반 문자
            }
        }

        return len;
    }
}