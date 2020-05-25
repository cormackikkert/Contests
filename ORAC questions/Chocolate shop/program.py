with open("chocin.txt") as file:
    NUM = int(file.readline())
    chocs = sum(map(int,file.readlines()))
    r = (10000000 - chocs) % 10

        
with open("chocout.txt", "w") as file:
    file.write(str(r))
