with open("probein.txt") as f:
    lines = f.readlines()
    l1 = lines[0].split()
    prob = (int(l1[2]), int(l1[3]))
    fiss = (int(l1[4]), int(l1[5]))
    
    points = []
    
    for i in range(2, len(lines)):
        l2 = lines[i].split()
        points.append((int(l2[0]), int(l2[1])))

    file = open("probeout.txt", "w+")
    
    for point in points:
        wDist = abs(prob[0] - point[0]) + abs(prob[1] - point[1])
        lDist = abs(fiss[0] - point[0]) + abs(fiss[1] - point[1])
        if wDist < lDist:
            file.write("WATER\n")
        elif lDist < wDist:
            file.write("LAVA\n")
        else:
            file.write("MOUNTAINS\n")
    
