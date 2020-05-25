N = int(input())
nums = list(map(int, input().split()))

BASIS_LENGTH = 32


def reduce(num):
    total = 0
    power = 0
    for i in range(BASIS_LENGTH):
        if bad & (1 << i): continue
        total += ((num & (1 << i)) >> i) * pow(2, power)
        power += 1
    return total
    
def expand(num):
    total = 0
    power = 0
    for i in range(BASIS_LENGTH):
        if bad & (1 << i):
            continue
        total += ((num & (1 << power)) >> power) * pow(2, i)
        power += 1
    return total

BASIS = [0 for i in range(BASIS_LENGTH)]
numsPrime = [reduce(n) for n in nums]


def insertVector(x):
    for i in range(BASIS_LENGTH -1, -1, -1):
        if x & (1 << i) == 0: continue
        if BASIS[i] == 0: BASIS[i] = x; return
        x ^= BASIS[i]
        
for x in numsPrime:
    insertVector(x)

def getSum():
    total = 0
    for el in reversed(BASIS):
        if el ==     0: continue
        if el ^ total > total:
            total = el ^ total
    return total

print(2*expand(getSum()) + bad)
