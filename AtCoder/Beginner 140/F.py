N = int(input())
nums = list(map(int, input().split()))

D = {}
L = 0
for n in nums:
    if n not in D:
        D[n] = L
        L += 1


for i, x in enumerate(sorted(D, reverse=True)):
    D[x] = i

arr = [0 for i in range(L)]
for n in nums:
    arr[D[n]] += 1

cumsum = [0 for i in range(L+1)]
for i in range(L):
    cumsum[i] = arr[i] + cumsum[i - 1]

# Deal with first
if arr[0] != 1:
    print("No")
    quit()

willSpawn = 1
cur = 1

while cur < L:
    if cumsum[cur - 1] < min(willSpawn, arr[cur]):
        print("No")
        quit()
    else:
        for i in range(willSpawn):
            arr[cur] -= 1
            while (cur < L) and arr[cur] == 0:
                cur += 1
    willSpawn *= 2

print("Yes")
