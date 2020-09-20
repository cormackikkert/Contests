import itertools
from subprocess import check_output
import random
import os
import time

def check(file1, file2):
    out1 = open(file1)
    out2 = open(file2)
    return out1.read().strip() == out2.read().strip()

for i in range(10000):
    with open("test.txt", "w") as file:
        N = 100000
        a1 = [random.randint(1, 100) for i in range(N)]
        b1 = [random.randint(1, 100) for i in range(N)]
        file.write(f"{N} \n")
        file.write(" ".join(map(str, a1)) + "\n")
        file.write(" ".join(map(str, b1)) + "\n")

    os.system(f"F.exe < test.txt > out.txt")

    with open("out.txt") as file:
        res = file.readline().strip()
        if res == "No": continue
        outa = list(map(int, file.readline().split()))
    for i in range(N):
        if outa[i] == a1[i]:
            print("REEE", 1/0)
    