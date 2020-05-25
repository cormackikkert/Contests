N = int(input())
N = pow(10, 6)
A = list(map(int, input().split()))

days = 0
last = -1
cur = 0
data = []
count = [0 for i in range(N+1)]
inOffice = [False for i in range(N+1)]

for i, event in enumerate(A):
    if event < 0:
        if inOffice[-event]:
            inOffice[-event] = False
            cur -= 1
        else:
            print(-1)
            quit()
    else:
        if inOffice[event]:
            print(-1)
            quit()
        else:
            if count[event] > days:
                print(-1)
                quit()
            else:
                count[event] = days + 1
                cur += 1
                inOffice[event] = True
    if cur == 0:
        data.append(i - last)
        days += 1
        last = i

if cur != 0:
    print(-1)
    quit()
print(len(data))
print(*data)
