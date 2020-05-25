N = int(input())
AS = list(map(int, input().split()))
BS = list(map(int, input().split()))
CS = list(map(int, input().split()))

total = 0
last = None
for x in AS:
    total += BS[x - 1]
    if x - 1 == last:
        total += CS[x - 2]
    last = x
print(total)
