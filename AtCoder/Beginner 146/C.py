A, B, X = map(int, input().split())
def cost(N):
    return A * N + B * len(str(N))

def binarySearch():
    l = 1
    h = int(pow(10, 9))
    while l < h:
        mid = l + (h - l + 1) // 2
        if cost(mid) <= X:
            l = mid
        else:
            h = mid - 1
    return l

res = binarySearch()
if cost(res) <= X:
    print(res)
else:
    print(0)
