with open("frogin.txt") as file:
    N, K = map(int, file.readline().split())
    pads = list(map(int, file.read().split()))

total = 0
nums = [0]
for i in range(N-1):
    total += K - pads[i]
    nums.append(total)

nums.sort()

total = -nums[len(nums)//2]
cost = abs(total)
for i in range(N-1):
    total += K - pads[i]
    cost += abs(total)

with open("frogout.txt", "w") as file:
    file.write(str(cost) + "\n")
