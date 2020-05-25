def gcd(a,b): 
      
    # Everything divides 0  
    if (b == 0): 
         return a 
    return gcd(b, a%b)

def lcm(a, b):
    return a * b // gcd(a, b)

def LCM(arr, n): 
    res = arr[0]
    for i in range(1, n):
        res = lcm(res, arr[i])
  
    return res; 
N, M = list(map(int, input().split()))
A = list(map(int, input().split()))
AH = [a//2 for a in A]

D = LCM(A, N)
O = D // 2

if (M == O):
    print(1)
elif (M > O):
    print((M-O) // D + 1)
else:
    print(0)