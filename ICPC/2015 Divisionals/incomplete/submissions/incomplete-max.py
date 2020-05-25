k, d = [int(x) for x in input().split()]
books = 1
tot = k
while tot <= d:
	k *= 2
	tot += k
	books += 1
print(books-1);
