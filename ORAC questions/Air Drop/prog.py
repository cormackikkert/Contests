with open("dropin.txt") as file:
	N = int(file.readline())
	placed = [False for i in range(10000000)]
	for i in range(N):
		placed[int(file.readline())-1] = True

dp = [[1 for i in range(N)] for j in range(10000000)]

highest = 0
for x in reversed(range(N)):
	if not placed[x]:
		continue
	dp[0][x] = 1
	cur = x+1
	for y in range(1, 10000000):
		if placed[cur] - placed[x] == y:
			dp[y][x] = 1 + dp[y][cur]
			cur += 1
		highest = max(highest, dp[y][x])
		if cur > N or x + y > N:
			break

with open("dropout.txt", "w") as file:
	file.write(str(highest))