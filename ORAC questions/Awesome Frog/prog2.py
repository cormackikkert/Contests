with open("frogin.txt") as file:
    N, K = map(int, file.readline().split())
    nums = [int(file.readline()) for i in range(N-1)]
    diff = [n - K for n in nums]
    shift = [None for i in range(N-1)] + [0]

t = 0
for i in range(N-2, -1, -1):
    t += diff[i]
    shift[i] = t
    
total = 0
lo_sink = 0
hi_sink = 0
for i in range(N-2):
    if (shift[i+1] == 0):
        if nums[i] - K > 0:
            while (lo_sink < N - 1) and (lo_sink <= i or nums[lo_sink] - K >= 0):
                lo_sink += 1
            if lo_sink - 1 - i < i + 1:
                nums[i+1] += nums[i] - K
                total += abs(nums[i] - K)
            else:
                total += (i+1) * abs(nums[i] - K)
        else:
            while (hi_sink < N -1) and (hi_sink <= i or nums[hi_sink] - K <= 0):
                hi_sink += 1
            if hi_sink - 1 - i < i + 1:
                nums[i+1] += nums[i] - K
                total += abs(nums[i] - K)
            else:
                total += (i+1) * abs(nums[i] - K)
    elif (nums[i] - K > 0) != (shift[i+1] > 0) or (shift[i+1] == 0 and ((nums[i] - K > 0) != (nums[i+1] - K > 0))):
        total += abs(nums[i] - K)
        nums[i+1] += nums[i] - K
    else:
        total += min(i+1, N-i-1) * abs(nums[i] - K)
total += abs(nums[N-2] - K)
print total
open("frogout.txt", "w").write(`total`)
