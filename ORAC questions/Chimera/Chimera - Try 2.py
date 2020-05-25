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

i = 0
while i < length:
	if s_lion <= s_snak and s_lion <= s_goat:
		x = f_lion.pop()
		if not done[x]:
			s_lion += 1
			s_snak += int(lion[x] == snak[x])
			s_goat += int(lion[x] == goat[x])
			i += 1
		done[x] = True

	elif s_snak <= s_lion and s_snak <= s_goat:
		x = f_snak.pop()
		if not done[x]:
			s_snak += 1
			s_lion += int(snak[x] == lion[x])
			s_goat += int(snak[x] == goat[x])
			i += 1
		done[x] = True

	elif s_goat <= s_lion and s_goat <= s_snak:
		x = f_goat.pop()
		if not done[x]:
			s_goat += 1
			s_lion += int(goat[x] == lion[x])
			s_snak += int(goat[x] == snak[x])
			i += 1
		done[x] = True

with open("chimout.txt", "w+") as file:
	file.write(str(min(s_lion, s_snak, s_goat)))