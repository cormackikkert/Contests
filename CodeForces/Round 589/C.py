x, n = map(int, input().split())

p = 1

# find prime factors of x
def isPrime(x):
    for i in range(2, min(x, int(x**0.5)+2)):
        if x % i == 0:
            return False
    return True

for i in range(2, int(x**0.5)+2):
    if x % i == 0 and isPrime(i):
        s = n
        t = 1
        while s >= i:
            s //= i
            p *= pow(s, i)
            p %= pow(10, 9) + 7
            t += 1

        print(p)
        s = n
        t = 1
        while s >= (x // i):
            s //= (x // i)
            p *= pow(s, (x // i))
            p %= pow(10, 9) + 7
            t += 1
        
print(p)
