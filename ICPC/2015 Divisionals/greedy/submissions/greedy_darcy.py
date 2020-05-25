coins = [1,2,5,10,20,50]

std = [int(x) for x in input().split()]
machine = std
T, ans = int(input()), 0

def make_change(amt):
    global machine
    tmp = amt
    for i in range(5,-1,-1):
        if tmp // coins[i] > machine[i]:
            return False
        tmp = tmp % coins[i]
    for i in range(5,-1,-1):
        machine[i] -= amt // coins[i]
        amt = amt % coins[i]
    return True

for _ in range(T):
    line = [int(x) for x in input().split()]
    V,d = line[0], line[1:]
    amt = sum(d[i]*coins[i] for i in range(6)) - V
    machine = [machine[i]+d[i] for i in range(6)]
    if make_change(amt): continue
    before = amt
    while not make_change(amt): amt += 1
    ans += amt-before
    machine = std

print(ans)
