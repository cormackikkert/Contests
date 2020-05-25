N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

AS = sorted(A)
BS = sorted(B)
for a, b in zip(AS, BS):
    if a > b:
        print("No")
        quit()

c = 0
for a, b in zip(A, B):
    if a <= b:
        c += 1

if c >= N :
    print("YES")
else:
    print("NO")
