with open("snapin.txt") as file:
	N = int(file.readline().strip())
	string = list(int(line)-1 for line in file.readlines())

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

with open("snapout.txt", "w+") as file:
    file.write(str(count))