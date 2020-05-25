with open("nortin.txt") as file:
    R, C = map(int, file.readline().split())
with open("nortout.txt", "w") as file:
    file.write(str(R * C - (R % 2 * C % 2)))
