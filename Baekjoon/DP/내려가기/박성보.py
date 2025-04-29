### 문제 정보 ###
# 문제 번호: 2096
# 문제 이름: 내려가기
# 문제 링크: https://www.acmicpc.net/problem/2096

### 문제 풀이 ###
# 1. 리스트 생성
## * nums: 입력 받는 숫자 저장
## * memo: [최대값, 최소값] 계산 결과 누적 저장, 초기값 = [max(nums[0]), min(nums[0]]
# 2. 입력 받은 숫자를 nums에 append, memo에는 [0, 0] 값 append
# 3. 이전에 선택한 숫자 위치(max_idx, min_idx)를 활용하여 이동 규칙 적용
## a. 이전에 왼쪽 수(0)를 선택했으면, 지금 선택할 수 있는 수는 왼쪽(0)과 중앙(1)
## b. 이전에 중앙(1)을 선택했으면, 지금 선택할 수 있는 수는 전부(0, 1, 2)
## c. 이전에 오른쪽(2)을 선택했으면, 지금 선택할 수 있는 수는 중앙(1)과 오른쪽(2)
# 4. 이동 규칙 중 예외 내용 적용
## * a와 c 방법에서 다음 최대(또는 최소)값이 멀리 있으면 지금 중앙 값 선택, 그렇지 않으면 최대(또는 최소)값 바로 선택
# 5. 이전 값이 필요 없어지면 삭제(pop)
# 6. 연산 중간에 max_idx, min_idx 변경을 방지하기 위해 max_idx_tmp, min_idx_tmp를 사용하여 연산 종료 후, 변경
# 7. n이 1 또는 2인 경우, 연산 방법 추가

import sys

n = int(sys.stdin.readline())

# 필요한 리스트 생성
## nums: 입력 받는 숫자 저장
## memo: [최대값, 최소값] 계산 결과 누적 저장
nums = []
memo = []

# 초기값 설정
nums.append(list(map(int, sys.stdin.readline().split(" "))))
memo.append([max(nums[0]), min(nums[0])])
max_idx = nums[0].index(max(nums[0]))
min_idx = nums[0].index(min(nums[0]))

# 반복 횟수를 제한할 변수
i = 0
while i < n-1:
    
    i += 1
    nums.append(list(map(int, sys.stdin.readline().split(" "))))
    memo.append([0, 0])
    
    if n == 2:
        if max_idx == 0:
            memo[1][0] = memo[0][0] + max(nums[-1][:2])
        if min_idx == 0:
            memo[1][1] = memo[0][1] + min(nums[-1][:2])
        if max_idx == 1:
            memo[1][0] = memo[0][0] + max(nums[-1])
        if min_idx == 1:
            memo[1][1] = memo[0][1] + min(nums[-1])
        if max_idx == 2:
            memo[1][0] = memo[0][0] + max(nums[-1][1:])
        if min_idx == 2:
            memo[1][1] = memo[0][1] + min(nums[-1][1:])
        memo.pop(0)
        break
    
    if len(nums) < 3:
        continue
    
    else:
        # 이전에 왼쪽 수(0)를 선택했으면, 지금 선택할 수 있는 수는 왼쪽(0)과 중앙(1)
        if max_idx == 0:
            # 다음 최대(또는 최소)값이 멀리 있으면 지금 중앙 값 선택
            if max(nums[2]) == max(nums[2][:2]):
                memo[1][0] = memo[0][0] + max(nums[1][:2])
                max_idx_tmp = nums[1].index(max(nums[1][:2]))
            # 그렇지 않으면 최대(또는 최소)값 바로 선택
            else:
                memo[1][0] = memo[0][0] + nums[1][1]
                max_idx_tmp = 1
        if min_idx == 0:
            if min(nums[2]) == min(nums[2][:2]):
                memo[1][1] = memo[0][1] + min(nums[1][:2])
                min_idx_tmp = nums[1].index(min(nums[1][:2]))
            else:
                memo[1][1] = memo[0][1] + nums[1][1]
                min_idx_tmp = 1
        
        # 이전에 중앙(1)을 선택했으면, 지금 선택할 수 있는 수는 전부(0, 1, 2)
        if max_idx == 1:
            memo[1][0] = memo[0][0] + max(nums[1])
            max_idx_tmp = nums[1].index(max(nums[1]))
        if min_idx == 1:
            memo[1][1] = memo[0][1] + min(nums[1])
            min_idx_tmp = nums[1].index(min(nums[1]))
        
        # 이전에 오른쪽(2)을 선택했으면, 지금 선택할 수 있는 수는 중앙(1)과 오른쪽(2)
        if max_idx == 2:
            # 다음 최대(또는 최소)값이 멀리 있으면 지금 중앙 값 선택
            if max(nums[2]) == max(nums[2][1:]):
                memo[1][0] = memo[0][0] + max(nums[1][1:])
                max_idx_tmp = nums[1].index(max(nums[1][1:]))
            # 그렇지 않으면 최대(또는 최소)값 바로 선택
            else:
                memo[1][0] = memo[0][0] + nums[1][1]
                max_idx_tmp = 1
        if min_idx == 2:
            if min(nums[2]) == min(nums[2][1:]):
                memo[1][1] = memo[0][1] + min(nums[1][1:])
                min_idx_tmp = nums[1].index(min(nums[1][1:]))
            else:
                memo[1][1] = memo[0][1] + nums[1][1]
                min_idx_tmp = 1
        
        # 이전 값이 계산에 필요 없으므로 삭제(메모리 초과 방지)
        if len(nums) == 3:
            nums.pop(0)
            memo.pop(0)
        
        # 연산 중간에 선택 값이 바뀌는 것을 방지하기 위해 tmp를 사용하여 연산 종료 후, 최종 변경
        max_idx, min_idx = max_idx_tmp, min_idx_tmp
        
        # 마지막이면 최대(또는 최소)값 더하기
        if i == n-1:
            memo[1][0] = memo[0][0] + max(nums[-1])
            memo[1][1] = memo[0][1] + min(nums[-1])
            memo.pop(0)
            
print(*memo[0])