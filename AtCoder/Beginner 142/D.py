A, B = map(int, input().split())

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

num = gcd(A, B)

if num < 2:
    print(1)
    quit()

length = int(num ** 0.5) + 2
isPrime = [True for i in range(length)]
isPrime[2] = True
for i in range(2, length):
    if isPrime[i]:
        for j in range(2 * i, length, i):
            isPrime[j] = False

count = 1

cur = 2
while num != 1 and cur < length:
    if isPrime[cur] and num % cur == 0:
        while num % cur == 0:
            num //= cur
        count += 1
    cur += 1

print(count + (num != 1))
