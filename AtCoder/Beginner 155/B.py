N = int(input())
AS = list(map(int, input().split()))

for x in AS:
    if x % 2 == 1: continue
    if (x % 3 != 0) and (x % 5 != 0):
        print("DENIED")
        break
else:
    print("APPROVED")
