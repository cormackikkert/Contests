with open("debtsin.txt") as file:
    NUM = int(file.readline())
    POS = [int(file.readline()) for i in range(NUM)]

def simulate(i):
    total = 0
    for j in range(NUM):
        if POS[i] > total:
            return False
        total -= POS[i]
        i = (i + 1) % NUM
    return True

inds = sorted(range(NUM), key = lambda n: POS[n-1], reverse=True)

result = -1

for i in inds:
    if simulate(i):
        result = i
        break

with open("debtsout.txt", "w") as file:
    file.write(str(result + 1))
