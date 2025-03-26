import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BJ_후위표기식 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String expression = st.nextToken();

        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (char ch : expression.toCharArray()) {
            if (Character.isAlphabetic(ch)) {
                // 피연산자: 바로 출력
                result.append(ch);
            } else if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    result.append(stack.pop());
                }
                stack.pop(); // '(' 제거
            } else { // 연산자
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                    if (stack.peek() == '(') {
                        break;
                    }
                    result.append(stack.pop());
                }
                stack.push(ch);
            }
        }

        // 스택에 남은 연산자 출력
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }
        System.out.println(result);
    }

    private static int precedence(char op) {
        if (op == '(' || op == ')') {
            return 0;
        }
        if (op == '+' || op == '-') {
            return 1;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        return -1; // 잘못됐을때
    }
}