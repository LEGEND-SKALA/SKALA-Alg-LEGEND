# 그래프 탐색 알고리즘 DFS/BFS

✔️ Graph는 무엇인가?

: 정점 Vertex와 간선 Edge로 이루어진 자료구조
![image](https://github.com/dannysmson/codingTestStudy/assets/79390749/1f6f3498-4536-4fe2-b9ac-c2ebcd3696b1)

---

✔️ Graph의 특징

- 방향성/무방향성

  그래프의 간선은 방향성이 있을 수 있으며, 없을 수도 있음

  방향성이 있는 경우 한쪽 방향으로만 이동 가능하며, 방향성이 없는 경우 양쪽 방향으로 이동 가능함

- 가중치 (Weight)

  간선에 **가중치**를 부여할 수 있으며, 거리, 비용 등을 나타내는 데 사용됨

- 차수 (Degree)

  한 정점에 인접한 간선의 수

---

✔️ Graph 구현 방법

- 인접 행렬 (Adjacency Matrix)

  : 2차원 배열로 그래프의 연결 관계를 표현하는 방식

- 인접 리스트 (Adjacency List)

  : 리스트로 그래프의 연결 관계를 표현하는 방식

<img width="772" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/2af90a6b-c9d5-4234-a46e-860fea27dc93">

---

✔️ DFS 알고리즘이란?

- Depth-First Search, 깊이 우선 탐색 알고리즘이며 그래프의 깊은 부분을 우선적으로 탐색하는 알고리즘

- 스택이나 재귀 호출을 사용하여 구현이 가능함

- 두 개의 정점 사이의 경로를 찾기, 그래프 내의 싸이클 찾기 등의 문제 해결 가능

- 시간 복잡도: 인접 행렬 O(V^2), 인접 리스트 O(V+E)

<img width="396" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/7c9ba317-ea4f-462e-8011-ea70ae44ad7f">

---

✔️ BFS 알고리즘이란?

- Breadth-First Search, 너비 우선 탐색 알고리즘이며 그래프에서 가까운 정점부터 탐색하는 알고리즘

- 큐를 사용하여 구현이 가능함

- 두 개의 정점 사이의 최소 간선을 사용하는 경로 찾기(최단 경로), 그래프 내의 싸이클 찾기 등의 문제 해결 가능

- 이진트리의 레벨순회와 유사

- 시간 복잡도: 인접 행렬 O(V^2), 인접 리스트 O(V+E)

<img width="396" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/4676fa13-8cb9-420e-a2b5-b9d073c4e400">

---

## BFS, DFS 문제예시

- 음료수 얼려 먹기 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/A.cpp]
- 미로 탈출 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/B.cpp]
- 특정 거리의 도시 찾기 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/Q15.cpp]
- 연구소 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/Q16.cpp]
- 경쟁적 전염 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/Q17.cpp]
- 괄호 변환 [https://github.com/dannysmson/codingTestStudy/blob/main/Graph_DFS_BFS/Q18.cpp]
