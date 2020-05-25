with open("vasesin.txt") as file:
    N = int(file.readline())

with open("vasesout.txt", "w") as file:
    if N >= 6:
        file.write("1 2 " + str(N - 3))
    else:
        file.write("0 0 0")
        
