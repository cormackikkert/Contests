done = {}

highest = 0
toSave = []
def memo(items, chosen):
    global highest
    global toSave
    
    if chosen in done:
        return done[chosen]
    
    time = sum(choose[0] for choose in chosen)
    items = tuple(item for item in items if (item not in chosen) and (item[1] > time + item[0]))

    if len(items) == 0:
        value = sum(choose[2] for choose in chosen)
        if value > highest:
            highest = value
            toSave = chosen
    else:
        value = max([memo(items, tuple(list(chosen) + [item])) for item in items])

    done[chosen] = value
    return value

itemNum = int(input())
items = tuple(tuple(map(int, input().split())) for i in range(itemNum))

print(memo(items, ()))
print(len(toSave))
print(*[items.index(thing)+1 for thing in toSave])
