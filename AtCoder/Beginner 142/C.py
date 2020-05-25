N = int(input())
arr = list(map(int, input().split()))

lst = sorted(range(1,N+1), key=lambda x:arr[x-1])

print(" ".join(map(str,lst)))
