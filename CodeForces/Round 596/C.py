N, P = map(int, input().split())

def countOnes(number):
    if number == 0: return 0
    return (number % 2) + countOnes(number >> 1)

digits = 1
while True:
    if N - digits * P < 0 or N - digits * P :
        print(-1)
        break

    if countOnes(N - digits * P) == digits:
        print(digits)
        break

    digits += 1

inn = [int(i) for i in input().split()]
n = inn[0]
p = inn[1]
i = 0
done = False
 
while (p < n):
    n -= p
    i += 1
    if(bin(n).count("1")<=i):
        print(str(i))
        done = True
        break
 
if (not done):
    print("-1")
