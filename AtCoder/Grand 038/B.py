arr = list(map(int, input().split()))

res = set()
for i in range(len(arr)):
    for j in range(i, len(arr)):
        t = arr[:i] + sorted(arr[i:j+1]) + arr[j+1:]
        res.add(tuple(t))
print(len(res))