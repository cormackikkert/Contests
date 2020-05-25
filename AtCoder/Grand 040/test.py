import itertools
from subprocess import check_output
import random
import os

def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1)
    out2 = open(file2)
    return int(out1.read()) == int(out2.read())

while True:
    with open("test.txt", "w") as file:
        T = random.randint(2, 3)
        file.write(str(T) + "\n")
        for i in range(T):
            n = random.randint(1, 10)
            s = random.randint(1, 10)
            file.write(f"{min(n, s)} {max(n, s)}\n")
            # file.write(" ".join([str(random.randint(1, pow(10, 9))) for i in range(n)]))


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("B.exe < test.txt > out1.txt")
    os.system("BTim.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
