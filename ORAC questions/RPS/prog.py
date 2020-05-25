with open("rpsin.txt") as file:
    N = int(file.readline())
    AR, AP, AS = map(int, file.readline().split())
    BR, BP, BS = map(int, file.readline().split())

# Win
RW = min(BR, AS)
PW = min(BP, AR)
SW = min(BS, AP)
BR -= RW; AS -= RW
BP -= PW; AR -= PW
BS -= SW; AP -= SW

# Draw
RD = min(AR, BR)
PD = min(AP, BP)
SD = min(AS, BS)
AR -= RD; BR -= RD
AP -= PD; BP -= PD
AS -= SD; BS -= SD

with open("rpsout.txt", "w") as file:
    file.write(str(RW+PW+SW-AR-AP-AS))
