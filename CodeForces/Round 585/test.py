import itertools
T = 1
from subprocess import check_output
import random
import os

def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1)
    out2 = open(file2)
    return out1.read().strip() == out2.read().strip()

count = 0
while True:
    count += 1
    print(count)
    if count % 10 == 0:
        print("Tested", count)
    with open("test.txt", "w") as file:
        N = 10
        file.write(str(N) + "\n")
        lst = [random.randint(1, 5) for i in range(N)]
        file.write(" ".join(map(str, lst)))


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)

    os.system("E.exe < test.txt > out1.txt")
    os.system("ETim.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
