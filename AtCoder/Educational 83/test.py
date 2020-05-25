import itertools
from subprocess import check_output
import random
import os


def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1).read().split()
    out2 = open(file2).read().split()
    return out1 == out2
    
while True:
    with open("test.txt", "w") as file:
        T = 1000
        file.write("{T}\n")
        for i in range(T):
            n = random.randint(1, 30)
            k = random.randint(2, 100)
            file.write(f"{n} {k}\n")
            file.write(" ".join([str(random.randint(1, pow(10, 16))) for i in range(n)]))
            file.write("\n")
        


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("CDillon.exe < test.txt > out1.txt")
    os.system("CRight.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
