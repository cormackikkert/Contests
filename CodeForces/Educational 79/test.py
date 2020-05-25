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
    T = int(fin.readline())
    for i in range(T):
        l1 = int(out1.readline())
        l2 = int(out2.readline())
        
        N, S = map(int, fin.readline().split())
        arr1 = list(map(int, fin.readline().split()))
        arr2 = list(arr1)
        if l1 >= 1: arr1[l1-1] = 0
        if l2 >= 1: arr2[l2-1] = 0
        return dist(arr1, S) == dist(arr2, S)
while True:
    with open("test.txt", "w") as file:
        file.write(str(T) + "\n")
        for i in range(T):
            n = random.randint(1, pow(10, 5))
            s = random.randint(1, pow(10, 9))
            file.write(f"{n} {s}\n")
            file.write(" ".join([str(random.randint(1, pow(10, 9))) for i in range(n)]))


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("BWrong.exe < test.txt > out1.txt")
    os.system("BIdeal.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
