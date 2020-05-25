with open("probein.txt") as file:
    r,c,px,py,fx,fy = list(map(int,file.readline().split()))
    points = []
    for i in range(int(file.readline())):
        points.append(list(map(int,file.readline().split())))

def solve(px, py, fx, fy, cx, cy):
    pdist = abs(px-cx)+abs(py-cy)
    fdist = abs(fx-cx)+abs(fy-cy)
    
    if abs(px-fx) == abs(py-fy):
        pdist = max(abs(px-cx),abs(py-cy))
        fdist = max(abs(fx-cx),abs(fy-cy))
    
    if pdist == fdist:
        return "MOUNTAINS"
    if pdist < fdist:
        return "WATER"
    if pdist > fdist:
        return "LAVA"
        
with open("probeout.txt", "w+") as file:
    for point in points:
        cx, cy = point
        file.write(solve(px, py, fx, fy, cx, cy)+"\n")
        
        

        
