import itertools
T = 1
from subprocess import check_output
import random
import os

while True:
    A = random.randint(0, pow(10, 18))
    B = random.randint(0, pow(10, 18))
    with open("test.txt", "w") as file:
        file.write(f"{A} {B}\n")

    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("HelloWorld.exe < test.txt > out.txt")
    if (int(open("out.txt").read()) != A *B): quit()
