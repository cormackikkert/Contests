def F(x):
    return x / sum(int(c) for c in str(x))

"""
for i in range(1, 100000): 
    if i > 10 and i % 10 != 9: continue
    if all(F(i) <= F(j) for j in range(i, 1 + int("9" * len(str(i))))):
        print(i)  
"""
K = int(input())

S = set()
for i in range(9): 
    S.add(i+1)

digits = 2
while len(S) < K:

    i = min(range(digits), key=lambda i: F(int("1"+"0"*(digits-i-1)+"9"*i)))

    # print(digits, i)
    S.add(int("9" * digits))
    for x in range(i, digits):
        for y in range(9): 
            if x + 1 == digits:
                S.add(int(str(y) + "9" * x))
            else:
                S.add(int("1" + "0" * (digits-x-2) + str(y) + "9" * x))
    digits += 1
S = sorted(S)
for i in range(K): print(S[i])