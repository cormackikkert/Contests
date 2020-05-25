N, L, R, K = map(int, input().split())
notes = list(map(int, input().split()))

allsegments = []
cur = None
for note1, note2 in zip(notes, notes[1:]):
    if cur == None:
        if note2 - note1 > 0:
            cur = ["U", 1]
        elif note2 - note1 < 0:
            cur = ["D", 1]
        else:
            cur = ["S", 1]
    else:
        if cur[0] == "U":
            if note2 - note1 > 0:
                cur[1] += 1
            else:
                allsegments.append(cur)
                if note2 == note1:
                    cur = ["S", 1]
                else:
                    cur = ["D", 1]
        elif cur[1] == "S":
            if note2 - note1 == 0:
                cur[1] += 1
            else:
                allsegments.append(cur)
                if note2 > note1:
                    cur = ["U", 1]
                else:
                    cur = ["D", 1]
        else:
            if note2 - note1 < 0:
                cur[1] += 1
            else:
                allsegments.append(cur)
                if note2 == note1:
                    cur = ["S", 1]
                else:
                    cur = ["U", 1]

allsegments.append(cur)

segments = [s[1] if s[0] == "U" else -s[1] for s in allsegments if s[0] != "S"]

los = [None for i in range(len(segments))]
his = [None for i in range(len(segments))]

for i, segment in enumerate(segments):
    if i == 0:
        los[0] = L + segment if segment > 0 else 0
        his[0] = R if segment > 0 else R + segment
        continue

    if segment > 0:
        los[i] = los[i-1] + segment
        his[i] = min(R, his[i-1] + abs(segment) * K)
    else:
        los[i] = max(L, los[i-1] - abs(segment) * K)
        his[i] = los[i-1] + segment

    if los[i] > R or his[i] < L:
        print(-1)
        quit()



results = []
curActualSegment = len(segments) - 1
curNote = N - 1
curHeight = los[curActualSegment]

if segments[0] > 0:
    los.append(max(L, los[0] - K * segments[0]))
else:
    los.append(los[0] - segments[0])
    
# length = A + B * K
def goUp(length, start, end):
    if length == 1:
        return [start]
    if length < end - start:
        use = min(K, end - start - length)
        return goUp(length - 1, start, end-use) + [end]
    else:
        return goUp(length - 1, start, end-1) + [end]

def goDown(length, start, end):
    return list(reversed(goUp(length, end, start)))

computed = []
for i in range(len(allsegments) - 1, -1, -1):
    lastSegment = allsegments[i]
    if lastSegment[0] == "S":
        results = []
        for i in range(lastSegment[1]):
            results.append(los[curActualSegment])
        computed.append(results)

    if lastSegment[0] == "U":
        result = goUp(lastSegment[1], los[curActualSegment-1] + 1, los[curActualSegment])
        computed.append(result)
        curActualSegment -= 1

    if lastSegment[0] == "D":
        result = goDown(lastSegment[1], los[curActualSegment-1] + 1, los[curActualSegment])
        computed.append(result)
        curActualSegment -= 1

actual = [los[-1]]
for thing in reversed(computed):
    actual += thing
print(*actual)
        
