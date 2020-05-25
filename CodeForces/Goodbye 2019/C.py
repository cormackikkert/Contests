arr = [1, 2, 3, 8]
oxor = 0
for item in arr: oxor ^= item
oxor = 0
N = 20
for i in range(N):
    for j in range(N):
        for k in range(N):
            if i ^ j ^ k >= i + j + k:
                print(i+j+k, i^j^k)
            """
            k = 0
            if sum(arr) + i + j + k == 2 * (oxor ^ i ^ j ^ k):
                print("SOLUTION: ", bin(sum(arr)), bin(oxor))
                print(bin(i))
                print(bin(j))
                print(bin(k))
            break
            """