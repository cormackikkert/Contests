n = int(input())
arr = list(map(int, input().split()))
total = 0

for i, ai in enumerate(arr):
    for aj in arr[i+1:]:
        if -1 <= ai - aj <= 1:
            continue
        total += aj - ai
        
print(total)
