with open("chimin.txt") as file:
    length = int(file.readline())
    data = {"G": 1, "C": 2, "A": 3, "T":4}
    
    lion = [data[char] for char in file.readline().strip()]
    snak = [data[char] for char in file.readline().strip()]
    goat = [data[char] for char in file.readline().strip()]


done = [False for i in range(length)]

f_lion = sorted(list(range(length)), key=lambda n:int(lion[n]==snak[n]) + int(lion[n]==goat[n])-int(snak[n]==goat[n]))
f_snak = sorted(list(range(length)), key=lambda n:int(snak[n]==lion[n]) + int(snak[n]==goat[n])-int(goat[n]==lion[n]))
f_goat = sorted(list(range(length)), key=lambda n:int(goat[n]==lion[n]) + int(goat[n]==snak[n])-int(lion[n]==snak[n]))

s_lion = 0
s_snak = 0
s_goat = 0

output = [None for i in range(length)]

while not all(done):
	i_lion = f_lion.pop()
	while done[i_lion]:
		i_lion = f_lion.pop()

	lion_move_scores = (
		s_lion + 1,
		s_snak + int(lion[i_lion] == snak[i_lion]),
		s_goat + int(lion[i_lion] == goat[i_lion]))

	i_snak = f_snak.pop()
	while done[i_snak]:
		i_snak = f_snak.pop()

	snak_move_scores = (
		s_lion + int(snak[i_snak] == lion[i_snak]),
		s_snak + 1,
		s_goat + int(snak[i_snak] == goat[i_snak]))

	i_goat = f_goat.pop()
	while done[i_goat]:
		i_goat = f_goat.pop()

	goat_move_scores = (
		s_lion + int(goat[i_goat] == lion[i_goat]),
		s_snak + int(goat[i_goat] == snak[i_goat]),
		s_goat + 1)
			
	
	if min(lion_move_scores) >= min(snak_move_scores) and min(lion_move_scores) >= min(goat_move_scores):
		s_lion, s_snak, s_goat = lion_move_scores
		done[i_lion] = True
		f_snak.append(i_snak)
		f_goat.append(i_goat)

	elif min(snak_move_scores) >= min(lion_move_scores) and min(snak_move_scores) >= min(goat_move_scores):
		s_lion, s_snak, s_goat = snak_move_scores
		done[i_snak] = True
		f_lion.append(i_lion)
		f_goat.append(i_goat)

	else:
		s_lion, s_snak, s_goat = goat_move_scores
		done[i_goat] = True
		f_lion.append(i_lion)
		f_snak.append(i_snak)

with open("chimout.txt", "w+") as file:
	file.write(str(min(s_lion, s_snak, s_goat)))