def op(x, N):
    if x % 2:
        x //= 2
    else:
        x //= 2 + pow(2, N - 1)
    return x

def calc(N):
    X = pow(2, N)

    ops = 2 * N * X

    ops = 2 * N * X

    total = {}
    for i in range(X):
        c = i
        count = 0
        while True:
            count += 1
            if c % 2:
                c = c >> 1
            else:
                c = (c >> 1) + pow(2, N - 1)
            if c == i: break
        if count != 2 * N:
            total[count] = total.get(count, 0)  + 1
            print(format(i, "0"+str(N)+"b"), count)
    print(total)
"""
X = input()
total = 0
for i, char in enumerate(reversed(X)):
    total += 2 * N * (char == '1') * pow(2, i)
print(total)
"""
