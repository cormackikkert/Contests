N = int(input())
A, B = input().split()
c = ""
for a, b in zip(A, B):
    c += a
    c += b
print(c)
