N = int(input())
C1 = [0 for i in range(60)]
C0 = [0 for i in range(60)]

V = list(map(int, input().split()))
for n in V:
    i = 0
    for i in range(60):
        if (n % 2 == 1):
            C1[i] += 1
        else:
            C0[i] += 1
        n //= 2
MOD = int(pow(10, 9) + 7)
total = 0;
for i in range(60):
    total += pow(2, i) * C1[i] * C0[i]
    total %= MOD
print(total)
    
