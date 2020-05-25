N = int(input())
S = input()

ones = set()
twos = set()
threes = set()

for c in S:
    for item in twos:
        threes.add(item + c)
    for item in ones:
        twos.add(item + c)
    ones.add(c)

print(len(threes))
