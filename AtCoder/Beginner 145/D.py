X, Y = map(int, input().split())
MOD = int(pow(10, 9) + 7)
def isValid(x, y):
    if (X + Y) % 3 != 0:
        return False
    S = (X + Y) // 3
    return Y >= S and X >= S

if not isValid(X, Y):
    print(0)
    quit()

S = (X + Y) // 3
A = (2 * X - Y) // 3

fact = [1 for i in range(S+1)]
for i in range(1, S+1): fact[i] = (i * fact[i - 1]) % MOD

def modInverse(x, power=MOD - 2):
    if power == 0: return 1
    cur = modInverse(x, power // 2); cur *= cur; cur %= MOD
    if power % 2 == 1:
        cur *= x
    cur %= MOD
    return cur


print((fact[S] * modInverse(fact[A]) * modInverse(fact[S-A])) % MOD)

