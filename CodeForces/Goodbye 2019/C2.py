def solve(arr):
    xor = 0
    for i in arr: xor^=i
    return [xor, sum(arr)+xor]

T = int(input())
for i in range(T): 
    _ = int(input())
    arr = list(map(int, input().split()))
    print(len(solve(arr)))
    print(" ".join(map(str, solve(arr))))