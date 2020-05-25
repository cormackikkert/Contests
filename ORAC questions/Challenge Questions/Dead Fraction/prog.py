with open("fraction.in") as file:
    numbers = list(iter(lambda:file.readline().strip('\n.'),'0'))

def gcd(a, b):
    while b != 0:
        b, a = a % b, b
    return a

for num in numbers:
    fill = int('9' * (len(num) - 2))
    num = num[2:]
    den = float('inf')
    for i in range(-len(str(fill)) + 1, len(str(fill))):
        div = gcd(int(num), i)
        if (i / div) % 1 == 0 and (i / div) < den:
            den = i / div
        print(den)
    print(num, den)
# with open("fraction.out") as file:
    
