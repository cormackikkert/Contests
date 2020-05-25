arr = list(map(int, input().split()))
N = len(arr)
K = 0
while True:
    arr.sort(reverse=True)
    print(arr)
    if (arr[0] >= N):
        arr[0] -= N
        for i in range(1, N): arr[i] +=1
        K+= 1

    else:
        break
print(K)