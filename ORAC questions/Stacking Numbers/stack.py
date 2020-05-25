with open("stackin.txt") as file:
    B = int(file.readline())
    M = int(file.readline())
    N = list(map(int, file.readline().split()))

score = lambda num:((num[0] + 4*num[1] + 6*num[2] + 4*num[3] + num[4]) % B) * ((num[1] + 4*num[2] + 6*num[3] + 4*num[4] + num[5]) % B)

maxResult = 0

for i, A in enumerate(N):
    for j, B in enumerate(N):
        if j in [i]:
            continue
        for k, C in enumerate(N):
            if k in [i, j]:
                continue
            for l, D in enumerate(N):
                if l in [i, j, k]:
                    continue
                for m, E in enumerate(N):
                    if m in [i, j, k, l]:
                        continue
                    for n, F in enumerate(N):
                        if n in [i, j, k, l, m]:
                            continue
                        result = score([A, B, C, D, E, F])
                        # print(result, [A, B, C, D, E, F])
                        if result > maxResult:
                            print("update", result, [A, B, C, D, E, F])
                            maxResult = result
                            res = [A, B, C, D, E, F]
print(res)
with open("stackout.txt", "w") as file:
    file.write(str(score(res)) + '\n')
    file.write(' '.join(map(str, res)) + '\n')




