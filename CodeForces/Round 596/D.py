N, K = map(int, input().split())
M = int(pow(10, 5) + 1)
total = 0
ints = list(map(int, input().split()))

counts = [0 for i in range(M)]
for j in ints:
    counts[j] += 1

if K > 2:
    consider = []
    for x in range(1, M):
        y = pow(x, K)
        if y <= M * M:
            consider.append(y)
        else:
            break

    for num, count in enumerate(counts):
        if num == 0: continue
        if count == 0: continue
        for target in consider:
            if target > num * num: break
            if target % num != 0: continue
            if target // num == num:
                total += (count * (count - 1)) // 2
            else:
                total += count * counts[target // num]

    print(total)
elif K == 2:
    n = N
    k = K
    nos = ints
    count = 0
    for i in range(len(nos)):
        if (nos[i]**(1/k)%1==0):
            print(nos[i])
            count += 1

    print(count)
    print(str(int(count*(count-1)/2)))

else:
    print((N - counts[1]) * counts[1])
