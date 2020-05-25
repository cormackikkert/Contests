N = int(input())
s = input()

leftSum = sum(int(c) for c in s[:N//2] if c != '?')
rightSum = sum(int(c) for c in s[N//2:] if c != '?')

leftOptions = 0
leftSum = 0
for c in s[:N//2]:
    if c == '?':
        leftOptions += 1
    else:
        leftSum += int(c)
        
rightOptions = 0
rightSum = 0
for c in s[N//2:]:
    if c == '?':
        rightOptions += 1
    else:
        rightSum += int(c)


remaining = abs(leftOptions - rightOptions)

if leftOptions > rightOptions:
    leftSum += remaining // 2 * 9
else:
    rightSum += remaining // 2 * 9
    
if leftSum == rightSum:
    print("Bicarp")
else:
    print("Monocarp")
