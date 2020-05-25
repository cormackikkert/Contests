from itertools import permutations

def dp(string, card=None):
    # Base cases:
    if card:
        if len(string) == 1:
            return string[0] == card
        if len(string) == 2:
            return max([string[0] == string[1], string[0] == card, string[1] == card])
    else:
        if len(string) == 2:
            return string[0] == string[1]
        elif len(string) == 1:
            return 0
    
    values = []
    if card:
        if card == string[0]:
            values += [1 + dp(string[1:])]
        elif card == string[1]:
            values += [1 + dp(string[0] + string[2:])]

    values += [dp(string[1:], string[0]), dp(string[0] + string[2:], string[1])]
    # print(string, card, max(values))
    return max(values)


for string in permutations([0, 0, 1, 1, 2, 2, 3, 3]):
	string = list(string)
	orig = list(string)
	N = 4

	result = dp("".join(map(str, string)))

indicies = [None for i in range(N)]
removed = [0 for i in range(N)]

for i, num in enumerate(string):
	indicies[num] = i

gofor = sorted(range(N), key=lambda n:indicies[n], reverse=True)

def take_fst():
	removed[string[~0]] += 1
	string.pop()

def take_snd():
	removed[string[~1]] += 1
	fst = string.pop()
	string.pop()
	string.append(fst)

	count = 0
	go = gofor.pop()
	string = list(reversed(string))
	while string:
		
		if go == None:
			while gofor:
				go = gofor.pop()
				if removed[go] == 0:
					break
			if gofor == [] and go == None:
				break

		if len(string) <= 1:
			break
		if len(string) == 2:
			count += int(string[~0] == string[~1])
			break

		if go == string[~0] and go == string[~1]:
			go = None
			count += 1
			take_fst()
			take_fst()

		elif go == string[~1] and go == string[~2]:
			go = None
			count += 1
			take_snd()
			take_snd()

		elif go == string[~0] and go == string[~2]:
			go = None
			count += 1
			take_fst()
			take_snd()

		elif go == string[~1]:
			take_fst()
		elif go == string[~0]:
			take_snd()
		elif removed[string[~0]] == 0 and removed[string[~1]] != 0:
			take_snd()
		elif removed[string[~0]] != 0 and removed[string[~1]] == 0:
			take_fst()
		elif indicies[string[~0]] < indicies[string[~1]]:
			take_snd()
		else:
			take_fst()
	if count != result:
		print(orig, count, result)