with open("hippoin.txt") as f:
    lines = f.readlines()
    l1 = lines[0].split()
    tulips, hippos, fences = map(int, l1)
    places = []
    for i in range(1, hippos + 1):
        places.append(int(lines[i]))
dirt = [False if i not in places else True for i in range(tulips)]
cost = []
for i in range(len(places) - 1):
    cost.append((2, len(dirt[places[i]+1:places[i+1]])))
cost.append((1, places[0]-1))
cost.append((1, len(dirt) - places[len(places)-1]))

for item in cost:
    if (item[1] <= 0):
        cost.remove(item)

f = list(cost)
highest = max([item for item in cost if item[0]==1], key=lambda x:x[1])
f.remove(highest)
dp = [[0, cost], [highest[1], f]]

for i in range(2, fences + 1):
    try:
        val1 = max([(dp[j][0] + max([item[1] for item in dp[j][1] if item[0] == 1]), j) for j in range(max(0, i-3),i)])
    except:
        val1 = (-1, -1)
    try:
        val2 = max([(dp[j][0] + max([item[1] for item in dp[j][1] if item[0] == 2]), j) for j in range(max(0, i-3),i-1)])
    except:
        val2 = (-1, -1)

    if val1 == (-1, -1) == val2:
        break
    
    if val2[0] > val1[0]:
        t = list(dp[val2[1]][1])
        t.remove((2, max(item[1] for item in t if item[0]==2)))
        dp.append((val2[0], t))

    else:
        t = list(dp[val1[1]][1])
        t.remove((1, max(item[1] for item in t if item[0]==1)))
        dp.append((val1[0], t))
    print(dp)
    
file = open("hippoout.txt", "w+")
file.write(str(max(dp, key=lambda x:x[0])[0]))
