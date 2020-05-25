n, k = map(int, input().split())
arr = input()

s = list(arr[:k])
for i in range(n):
    if arr[i%k] < arr[i]:
        if i >= k:
            i = k - 1
            while s[i] == '9':
                s[i] = '0'
                i -= 1
            s[i] = str(int(s[i]) + 1)
        else:
            s[i] = str(int(s[i]) + 1)
        break
    if arr[i%k] > arr[i]: break

print(n)
v = "".join(s)
for i in range(n//k):
    print(v,end='')
print(v[:n%k])
