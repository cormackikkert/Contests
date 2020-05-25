N = 4
arr = [1, 2, 3, 4]
MOD = pow(10, 9) + 7

def bruteForce(arr):
    if len(arr) == 1: return 0
    total = 0
    for i in range(len(arr) - 1):
        copy = list(arr)
        total += copy[i+1] - copy[i]
        copy.remove(copy[i])
        total += bruteForce(copy)
        total %= MOD
    print(arr, total)
    return total

print(bruteForce([1, 2, 4]))