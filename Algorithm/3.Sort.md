# Sorting Algorithm

✔️ 정렬이란?

: 데이터를 특정한 기준에 따라서 순서대로 나열하는 것

___

✔️ 선택정렬 Selection Sort

: 정렬 되어있지 않은 인덱스의 맨 앞에서 부터, 이후의 배열 값 중 `가장 작은 값`을 찾아내어 위치를 바꾸는 과정을 반복하는 방법 (오름차순 정렬 기준)

* `제자리 정렬` - 추가적인 메모리 공간을 필요로 하지 않고 구현이 가능하다
* `불안정 정렬` - 정렬 후에 같은 값의 요소들의 순서가 보장되지 않음
* 구현은 쉽지만 배열의 상태가 어떻게 되어있든 `O(N^2)`의 시간복잡도를 가진다.
  
선택정렬 예시
  
<img width="643" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/6918a777-1bb5-4cfc-a7c2-840caf4800a7">


c++ 구현 코드링크 - [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/selectionSort.cpp]

___

✔️ 삽입정렬 Insertion Sort

: 특정한 데이터를 넣을 적절한 위치를 찾아 `삽입`하는 정렬 방법

* `제자리 정렬` - 추가적인 메모리 공간을 필요로 하지 않고 구현이 가능하다
* `안정 정렬` - 정렬 후에 같은 값의 요소들의 순서가 보장됨
* 시간 복잡도: 최악의 경우 `O(N^2)`, 최선의 경우 `O(N)` - 배열이 **완전히** 또는 **거의** 정렬되어 있는 경우

삽입정렬 예시

<img width="643" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/70973dae-cf9d-4d03-b74f-5329de8f1414">

c++ 구현 코드링크 - [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/insertionSort.cpp]

___

✔️ 퀵 정렬 Quick Sort

: 기준 데이터인 `피벗`을 설정하고 그 기준보다 큰 데이터오아 작은 데이터의 위치를 바꾸어 가며 정렬하는 방법

* `제자리 정렬` - 추가적인 메모리 공간을 필요로 하지 않고 구현이 가능하다
* `불안정 정렬` - 정렬 후에 같은 값의 요소들의 순서가 보장되지 않음
* `분할통치법` - 입력 데이터를 둘 이상의 부분집합으로 `분할`, 부문제를 `재귀`적으로 해결하고, 부문제들의 해결을 합침 `(통치)` 
* 다른 정렬 알고리즘에 비해 속도가 매우 빠름. 평균 시간 복잡도: `O(NlogN)`, 최악의 경우 `O(N^2)` - 피벗값을 설정할 때 이미 데이터들이 반대로 정렬되어 있는 경우

퀵 정렬 예시

<img width="635" alt="image" src="https://github.com/dannysmson/codingTestStudy/assets/79390749/6ac27d68-4fd4-4187-9f70-91f51e8c4a0c">

c++ 구현 코드링크 - [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/quickSort.cpp]

___

✔️ 힙 정렬 Heap Sort

: `완전 이진트리`를 기본으로 하는 `힙` 자료구조를 기반으로 한 정렬 방법

* `제자리 정렬` - 추가적인 메모리 공간을 필요로 하지 않고 구현이 가능하다
* `불안정 정렬` - 정렬 후에 같은 값의 요소들의 순서가 보장되지 않음
* 시간복잡도: `O(NlogN)`
  - 힙을 구성하는 과정에서 트리의 높이만큼 비교를 하므로 logN, 이 과정을 N번 진행해야 하므로 NlogN
  - 힙에서 노드를 N번 추출, 줄어든 힙에서 다시 힙을 구성해야 하므로 NlogN
* 힙 정렬 vs 퀵 정렬
  - 요소의 갯수가 증가하면 증가할 수록, swap연산을 진행하는 횟수가 힙 정렬이 많기에 퀵 정렬이 조금 더 빠르다고 할 수 있다.



> ✔️ 이진 트리 개념과 종류 (Binary Tree)
>
> * `이진 트리 (Binary Tree)`
>
>   : 모든 노드들이 둘 이하의 자식을 가진 트리
>
> * `이진 탐색 트리 (Binary Search Tree, BST)`
>
>   : 이진 트리이며, 부모 노드 기준 왼쪽 자식은 작고, 오른쪽 자식은 큰 조건을 만족시키는 트리
>
> * `정 이진 트리 (Full Binary Tree)`
>
>   : 모든 노드가 0개 또는 2개 자식 노드를 갖는 트리
>
> * `완전 이진트리 (Complete Binary Tree)`
>
>   : 마지막 레벨을 제외하고 모든 레벨이 완전히 채워져 있는 트리 (왼쪽부터 노드가 채워져있어야 함)
>
> * `포화 이진트리 (Perfect Binary Tree)`
>
>   : 빈 곳 없이 꽉차있는 트리
>
> * `높이 균형 이진 탐색 트리 (Adelson-Velsky and Landis, AVL 트리)`
>
>   : 왼쪽과 오른쪽 자식의 높이 차가 1이하가 되도록 유지하는 트리

* 최대힙

: 부모노드의 키 값이 항상 자식 노드의 키값보다 큰 힙 자료구조 (오름차순 정렬에 사용)

* 최소힙

: 부모노드의 키 값이 항상 자식 노드의 키값보다 작은 힙 자료구조 (내림차순 정렬에 사용)

* 동작 과정 (배열)

  - 배열 인덱스 특성 상 루트 노드의 인덱스를 0이 아닌 1로 초기화
  - 배열 요소들을 입력받고 힙 자료구조 생성 (최대힙)
  - 자식노드부터 부모노드 순으로 upHeap을 진행하고, 최대힙이니 자식노드의 키값이 부모노드의 키값보다 클 경우 swap
  - 최대힙을 구성한 후, 다음 과정 N번 반복
  - 루트 노드와 마지막 리프노드를 swap, 다시 최대힙 생성

c++ 구현 코드링크 - [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/heapSort.cpp]

___
## 정렬 알고리즘 문제예시
* 위에서 아래로 [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/A.cpp]
* 성적이 낮은 순서로 학생 출력하기 [https://github.com/dannysmson/codingTestStudy/blob/main/Sort/B.cpp]
