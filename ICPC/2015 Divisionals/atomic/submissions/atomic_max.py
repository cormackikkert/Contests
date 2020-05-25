N = int(input())
atoms = {}
for _ in range(N):
	name, w = input().split()
	atoms[name] = float(w)

mol = input()
ans = 0.0
i = 0
while i < len(mol):
	elem = mol[i]
	num = ""
	i += 1
	while i < len(mol) and not mol[i].isupper() and not mol[i].isdigit():
		elem += mol[i]
		i += 1
	while i < len(mol) and mol[i].isdigit():
		num += mol[i]
		i += 1
	if num == "":
		num = "1"
	ans += atoms[elem] * int(num)

print(ans)
