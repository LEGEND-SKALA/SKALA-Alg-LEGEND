package org.bj;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

public class BJ_1593 {
    static HashMap<Character, Integer> map = new LinkedHashMap<>();
    static HashMap<Character, Integer> targetMap = new LinkedHashMap<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int result = 0;
        int wlen = Integer.parseInt(st.nextToken()); // 패턴 길이
        int slen = Integer.parseInt(st.nextToken()); // 문자열 길이
        char[] warray = br.readLine().toCharArray(); // 패턴 문자 배열
        char[] sarray = br.readLine().toCharArray(); // 문자열 문자 배열

        for (int i = 0; i < wlen; i++) {
            targetMap.put(warray[i], targetMap.getOrDefault(warray[i], 0) + 1);
        }

        for (int i = 0; i < wlen; i++) {
            map.put(sarray[i], map.getOrDefault(sarray[i], 0) + 1);
        }

        if (map.equals(targetMap)) {
            result++;
        }

        for (int i = wlen; i < slen; i++) {
            char addKey = sarray[i]; // 새로 추가할 문자
            char removeKey = sarray[i - wlen]; // 제거할 문자

            map.put(addKey, map.getOrDefault(addKey, 0) + 1);

            if (map.get(removeKey) > 1) {
                map.put(removeKey, map.get(removeKey) - 1);
            } else {
                map.remove(removeKey);
            }
            if (map.equals(targetMap)) {
                result++;
            }
        }

        System.out.println(result);
    }
}
