pairs=set()
with open("invin.txt") as file:
    rows, cols = map(int,file.readline().split())
    line1=list(file.readline())
    line2=list(file.readline())
    for i in range(rows-2):
        for i in range(cols-1):
            if line1[i] != line2[i]:
                down_pair = {line1[i], line2[i]}
            if line1[i]
        
