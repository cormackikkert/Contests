import itertools
T = 1
from subprocess import check_output
import random
import os

def dist(arr, S):
    n = 0
    for item in arr:
        S -= item
        if S >= 0 and item > 0: n += 1
        if S < 0:
            break
    return n

def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1)
    out2 = open(file2)
    return out1.read().strip() == out2.read().strip()
while True:
    with open("test.txt", "w") as file:
        N, K = random.randint(1, 5), random.randint(1, 5)
        file.write(f"{N} {K}\n")
        file.write(" ".join([str(random.randint(1, 5)) for i in range(N)]))


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("B.exe < test.txt > out1.txt")
    os.system("BBruteForce.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
