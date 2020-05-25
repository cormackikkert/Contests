with open("snapin.txt") as file:
	N = int(file.readline().strip())
	string = tuple(int(line) for line in file.readlines())

indicies = [None for i in range(N+1)]
for i, num in enumerate(string):
	indicies[num] = i
print(indicies)
done = {}
def solve(string, x=0):
	if len(string) <= 1:
		return 0
	if len(string) == 2:
		return int(string[0] == string[1])
	if string in done:
		return done[string]
	f = string[0]
	s = string[1]
	# print(string, tuple(string[1:]), tuple((string[0],) + string[2:]))
	ans =  max(solve(tuple(string[1:]), x + 1),
			   solve(tuple((string[0],) + string[2:]), x + 1))
	# print(string, indicies[f], x)
	if x + 1 < indicies[f]:
		ans = max(ans, 1 + solve(tuple(string[indicies[f]-x+1:]), indicies[f]))
	if x + 2 < indicies[s]:
		ans = max(ans, 1 + solve(tuple(string[indicies[s]-x+1:]), indicies[s]))
	done[string] = ans
	return ans

print(solve(string))
