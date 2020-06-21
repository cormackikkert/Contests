S = input()
K = int(input())

def getOperations(s):
    inds = set()
    poss = set()
    for i, c in enumerate(s):
        if c == '0': 
            for j in inds:
                news = s[:i] + s[i+1:]
                poss.add(news[:j] + '0' + news[j:])
        else:
            inds.add(i)
    return poss

# BFS
dist = {}
dist[S] = 0
queue = [S]
T = [[] for i in range(len(S))]
while len(queue) > 0:
    curs = queue.pop(0)
    T[dist[curs]].append(curs)
    for news in getOperations(curs):
        if (news not in dist):
            queue.append(news)
            dist[news] = dist[curs] + 1

for lst in T:
    lst.sort(reverse=True)
    print(lst)