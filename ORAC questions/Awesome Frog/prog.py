with open("frogin.txt") as file:
    N, K = map(int, file.readline().split())
    nums = [int(file.readline()) for i in range(N-1)] + [0]

total = 0
hi_absorb = 0
lo_absorb = 0

for i in range(N-1):
	l_sum = (i + 1) * abs(nums[i] - K)
	r_sum = (N-i-1) * abs(nums[i] - K)
	if nums[i] - K > 0:
		while (lo_absorb < N-2) and (i >= lo_absorb or nums[lo_absorb] - K >= 0):
			lo_absorb += 1

		if lo_absorb != i:

			r_dist = (lo_absorb - i) * (nums[i] - K)
			if abs(nums[lo_absorb] - K) >= abs(nums[lo_absorb] + nums[i] - K - K) and l_sum >= abs(r_dist) and r_sum >= abs(r_dist):
				nums[lo_absorb] += nums[i] - K
				total += abs(r_dist)
				continue

	else:
		while (hi_absorb < N-2) and (i >= hi_absorb or nums[hi_absorb] - K <= 0):
			hi_absorb += 1

		if hi_absorb != i:
			change = nums[i] - K
			r_dist = (hi_absorb - i) * (nums[i] - K)
			if abs(nums[hi_absorb] - K) >= abs(nums[hi_absorb] + nums[i] - K - K) and l_sum >= abs(r_dist) and r_sum >= abs(r_dist):
				nums[hi_absorb] += nums[i] - K
				total += abs(r_dist)
				continue

	total += min(l_sum, r_sum)
print(total)
open("frogout.txt", "w").write(str(total))
