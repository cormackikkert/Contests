N = int(input())
string = input()
total = 0
cur = None
for c in string:
    if c != cur:
        total += 1
        cur = c
print(total)
