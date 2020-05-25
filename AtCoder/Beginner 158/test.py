import itertools
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
    l1 = int(out1.readline())
    l2 = int(out2.readline())
    return l1 == l2

while True:
    with open("test.txt", "w") as file:
        n = random.randint(1,2)
        s = 2
        file.write(f"{n} {s}\n")
        file.write("".join([str(random.randint(0, 9)) for i in range(n)]))


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("E.exe < test.txt > out1.txt")
    os.system("ERight.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
