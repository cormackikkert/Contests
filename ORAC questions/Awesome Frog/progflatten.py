with open("frogin.txt") as file:
    N, K = map(int, file.readline().split())
    N = N - 1
    nums = [float('-inf')] + [int(file.readline()) for i in range(N)] + [float('inf')]

lSink = [None for i in range(N+2)]
rSink = [None for i in range(N+2)]

last = 0
for i,n in enumerate(range(N+2)):
    last += 1
    if n - K < 0:
        last = 0
    lSink[i] = last
    
last = 0
for i,n in enumerate(reversed(range(N+2))):
    last += 1
    if n - K < 0:
        last = 0
    rSink[N-1-i] = last

indexes = range(1,N+1)
indexes.sort(reverse=True)
total = 0
for i in indexes:
    if nums[i] >= K: continue
    l,r = lSink[i], rSink[i]
    while nums[i] > K:
        while nums[i-l] >= K:
            l -= lSink[l-1] + 1
        while nums[i+r] >= K:
            r += rSink[r+1] + 1

        if l < r:
            cap = K - nums[i - l]
            nums[i - l] += min(cap, nums[i] - K)
            nums[i] -= min(cap, nums[i] - K)
            total += min(cap, nums[i] - K) * l
        else:
            cap = K - nums[i + r]
            nums[i + r] += min(cap, nums[i] - K)
            nums[i] -= min(cap, nums[i] - K)
            total += min(cap, nums[i] - K) * r

print total
