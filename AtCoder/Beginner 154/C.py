N = int(input())
arr = list(map(int, input().split()))
arr.sort()

for i in range(1, N):
    if arr[i] == arr[i-1]:
        print("NO")
        quit()
print("YES")