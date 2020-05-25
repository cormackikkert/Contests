"""
ID: cormac.1
LANG: PYTHON3
TASK: game1
"""

with open("game1.in") as file:
    N = int(file.readline())
    nums = list(map(int, file.read().split()))

dp = [[None for i in range(N)] for j in range(N)]

for i, num in enumerate(nums):
    dp[0][i] = (num, True)

for y in range(1, N):
    for x in range(N-y):
        left = nums[x] - dp[y-1][x+1][0]
        right = nums[x+y] - dp[y-1][x][0]
        if left < right:
            dp[y][x] = (right, True)
        else:
            dp[y][x] = (left, False)
            
CUR_LEFT = 0
CUR_RIGHT = N - 1

RESULT = N-1

A_SCORE = 0

while RESULT >= 0:
    action = dp[RESULT][CUR_LEFT][1]

    if action:
        # Take right
        A_SCORE += ((N-RESULT) % 2) * nums[CUR_RIGHT]
        CUR_RIGHT -= 1
    else:
        # Take left
        A_SCORE += ((N-RESULT) % 2) * nums[CUR_LEFT]
        CUR_LEFT += 1
        
    RESULT -= 1

with open("game1.out", "w") as file:
    file.write(str(A_SCORE) + " " + str(sum(nums) - A_SCORE) + "\n")
    
        
