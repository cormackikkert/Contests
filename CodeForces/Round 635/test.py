import itertools
T = 1
from subprocess import check_output
import random
import os

def check(file1, file2):
    fin = open("test.txt")
    out1 = open(file1)
    out2 = open(file2)
    return out1.read() == out2.read()

count = 0
while True:
    count += 1
    print(count)
    if count % 10 == 0:
        print("Tested", count)
    with open("test.txt", "w") as file:
        file.write("1\n")
        R, G, B = int(random.randint(1, pow(10,5))),int(random.randint(1, pow(10,5))),int(random.randint(1, pow(10,5)))
        file.write(f"{R} {G} {B}\n")
        file.write(" ".join(map(str, [[1,random.randint(pow(10, 9)//2, pow(10, 9))][random.random()>0.2] for i in range(R)]))+"\n")
        file.write(" ".join(map(str, [[1,random.randint(pow(10, 9)//2, pow(10, 9))][random.random()>0.2] for i in range(B)]))+"\n")
        file.write(" ".join(map(str, [[1,random.randint(pow(10, 9)//2, pow(10, 9))][random.random()>0.2] for i in range(G)]))+"\n")


    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)

    os.system("D.exe < test.txt > out1.txt")
    os.system("D3.exe < test.txt > out2.txt")

    if not check("out1.txt", "out2.txt"): quit()
