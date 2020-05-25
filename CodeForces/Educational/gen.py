import itertools
n = 4
from subprocess import check_output

import os

for item in itertools.permutations([i+1 for i in range(2*n)]):
    with open("test.txt", "w") as file:
        file.write(str(n) + "\n")
        for i in range(n):
            file.write(f"{item[2*i]} {item[2*i+1]}\n")
    # if (item == (1, 4, 3, 6, 2, 5)): break
    # print(item, end = " ", flush=True)
    os.system("Round78_D.exe < test.txt")
    os.system("ideal.exe < test.txt")
    
