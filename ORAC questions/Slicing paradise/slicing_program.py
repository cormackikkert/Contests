with open("slicein.txt") as file:
    N = int(file.readline())
    fors = list(map(int,[file.readline() for i in range(N)]))


def count_park(time):
    parks = []
    curre = 0
    while curre < N:
        
        # Find next resort
        length = 0
        while curre < N and fors[curre] > time:
            curre += 1
            length += 1


        # Find next parkland
        while curre < N and fors[curre] <= time:
            curre += 1

        if length > 0:
            parks.append(length)
            
    return len(parks), parks

max_val = 0
for i in range(N):
    results = count_park(i + 1)
    
    if results[0] > max_val:
        max_val = results[0]

    if max(results[1]) <= 2:
        break

with open("sliceout.txt", "w") as file:
    file.write(str(max_val))

