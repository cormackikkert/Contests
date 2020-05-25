import sys
sys.setrecursionlimit(1000000)

with open("detectivein.txt") as file:
	N, M = map(int, file.readline().split())

	cla = [[] for i in range(N)]
	sam = [[] for i in range(N)]
	opp = [[] for i in range(N)]
	ans = [True for i in range(N)]

	t = [[] for i in range(N)]

	for i in range(M):
		A, B, T = map(int, file.readline().split())
		if T == 1:
			sam[A-1].append(B-1)
			sam[B-1].append(A-1)
		elif T == 2:
			opp[A-1].append(B-1)
			opp[B-1].append(A-1)
		elif T == 3:
			cla[A-1].append(B-1)
			if len(t[B-1]) >= 1:
				sam[A-1].append(t[B-1][0])
				sam[t[B-1][0]].append(A-1)
			t[B-1].append(A-1)
	
def dfs(v, parity):
	global failed
	disc[v] = parity
	comp[parity].append(v)

	for n in sam[v]:
		if disc[n] == None:
			dfs(n, parity)
		elif disc[n] != parity:
			failed = True
	for n in opp[v]:
		if disc[n] == None:
			dfs(n, 1-parity)
		elif disc[n] == 1-parityity:
			failed = True

disc = [None for i in range(N)]
comp = [[],[]]
failed = False
flag = False
force = set()
impos = set()
for i in range(N):
	if disc[i] != None:
		continue

	failed = False
	comp = [[], []]
	dfs(i, 0)

	if failed == True:
		flag = True
		break	
	
	LC = set([v for L in comp[0] for v in cla[L]])
	RC = set([v for R in comp[1] for v in cla[R]])

	if LC & RC != set():
		flag = True
		break
	
	a = len(LC)
	b = len(RC)

	if a > 1 and b > 1:
		flag = True
		break

	if force == set():
		if a >= 2:
			if b == 1:
				force = RC
			else:
				impos |= LC
		elif b >= 2:
			if a == 1:
				force = LC
			else:
				impos |= RC
		elif a == b == 1:
			force = LC | RC
	elif (a >= 1 and b >= 2) or (a >= 2 and b >= 1):
		flag = True
		break

with open("detectiveout.txt", "w") as file:
	if flag:
		file.write("MISTAKE\n")
	elif force == set():
		if len(impos) == N:
			file.write("MISTAKE\n")
		else:
			for i in range(N):
				if i not in impos:
					file.write(str(i+1) + "\n")
	else:
		for i in range(N):
			if i in force:
				file.write(str(i+1) + "\n")