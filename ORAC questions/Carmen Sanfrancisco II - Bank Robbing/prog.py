with open("wherein.txt") as file:
	N, C = map(int, file.readline().split())
	isBank = [False for i in range(N)]
	banks = list(map(int,file.readline().split()))
	lo, hi = banks[0]-1, banks[-1]-1
	for bank in banks:
		isBank[bank-1] = True
	closeTimes = list(map(int, file.readline().split()))

rTimes = [None for i in range(N)]
lTimes = [None for i in range(N)]

rBridges = [time for i, time in enumerate(closeTimes) if i < hi]
rClose = sorted(zip([rBridges[i] - i for i in range(hi)], range(hi)), reverse=True)
rTimes = [None for i in range(N)]
if rClose != []:
	curLow = rClose.pop()
	done = [None]

	for i in range(hi):
		while curLow[1] < i:
			if rClose == []:
				break
			curLow = rClose.pop()
		rTimes[i] = curLow[0] + i - 1
	rTimes[hi] = float('inf')

lBridges = [time for i, time in enumerate(closeTimes) if i >= lo]
lClose = sorted(zip([lBridges[i - lo] - (N - 1 - i) for i in range(lo, N-1)], range(lo, N-1)), reverse=True)
if lClose != []:
	lTimes = [None for i in range(N)]
	curLow = lClose.pop()
	for i in range(N-1, lo, -1):
		while curLow[1] >= i:
			if lClose == []:
				break
			curLow = lClose.pop()
		lTimes[i] = curLow[0] + (N - i - 1)
	lTimes[lo] = float('inf')

total = 0
for i in range(N):
	if i == lo == hi:
		total += rTimes[i] >= 0 or lTimes[i] >= 0
	elif i <= lo:
		total += rTimes[i] >= 0
	elif i >= hi:
		total += lTimes[i] >= 0
	else:
		total += (lTimes[hi] >= (hi - i) and rTimes[i] >= 0) or (rTimes[lo] >= (i - lo) and lTimes[i] >= 0)

with open("whereout.txt", "w") as file:
	file.write(str(total))