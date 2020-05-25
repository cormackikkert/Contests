with open("taxiin.txt") as file:
    S = int(file.readline())
    N = int(file.readline())
    Taxis = [tuple(map(int, file.readline().split())) for i in range(N)]

new = []
for cost, people in Taxis:
    new.append((cost, people))
    new.append((cost, people - 1))

Taxis = sorted(new, key = lambda n: n[0]/n[1])
print(Taxis)
cost = 0
person = 0
while person < S:
    flag = False
    for c, p in Taxis:
        if person + p >= S:
            cost += c
            person += p
            flag = True
            break
        
    if flag == False:
        c, p = Taxis[0]
        cost += c
        person += p

print(cost)
# with open("taxiout.txt", "w") as file:
#     file.write(str(dp[-1]))
