import itertools
T = 1
from subprocess import check_output
import random
import os

def check(file1, file2):
    return open(file1).read() == open(file2).read()
    
while True:
    with open("test.txt", "w") as file:
        file.write(str(T) + "\n")
        for i in range(T):
            n = 5
            file.write(f"{n}\n")
            file.write(" ".join([str(random.randint(1, 10)) for i in range(n)]) + "\n")
            file.write(" ".join([str(random.randint(1, 10)) for i in range(n)]) + "\n")


    # if (item == (1, 4, 3, 6  , 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("F.exe < test.txt > out1.txt")
    os.system("F2.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
