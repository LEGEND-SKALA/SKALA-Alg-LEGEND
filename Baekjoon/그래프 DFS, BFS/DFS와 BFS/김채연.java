import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, V, start = 0;
    static boolean[] visited;
    static List<Integer>[] list;
    static StringBuilder sb1 = new StringBuilder();
    static StringBuilder sb2 = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(st.nextToken());

        list = new ArrayList[N + 1];

        for (int i = 0; i <= N; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < V; i++) {
            st = new StringTokenizer(br.readLine());
            int point = Integer.parseInt(st.nextToken());
            int near = Integer.parseInt(st.nextToken());
            list[point].add(near);
            list[near].add(point);
        }
        for (int i = 0; i <= N; i++) {
            Collections.sort(list[i]);
        }

        visited = new boolean[N + 1];
        sb1.append(start).append(" ");
        visited[start] = true;
        dfs(start);
        visited = new boolean[N + 1];
        bfs(start);
        System.out.println(sb1);
        System.out.println(sb2);
    }

    private static void dfs(int start) {
        for (int node : list[start]) {
            if (!visited[node]) {
                sb1.append(node).append(" ");
                visited[node] = true;
                dfs(node);
            }
        }
    }

    private static void bfs(int start) {
        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(start);
        sb2.append(start).append(" ");
        visited[start] = true;
        while (!dq.isEmpty()) {
            int current = dq.poll();
            for (int node : list[current]) {
                if (!visited[node]) {
                    visited[node] = true;
                    sb2.append(node).append(" ");
                    dq.add(node);
                }
            }
        }
    }
}

