import itertools
T = 1
from subprocess import check_output
import random
import os
import itertools
def calc(arr):
    arr = [(i, ind) for ind, i in enumerate(arr)]
    best = 0
    for it in itertools.permutations(arr):
        tot = 0
        for item in it:
            tot += abs(arr.index(item) - it.index(item)) * item[0]
        best = max(best, tot)
    return best
def check(file1, ans):
    out1 = open(file1)
    x = int(out1.read().strip())
    print(x, ans)
    return x == ans

count = 0
while True:
    N = 6
    arr = [random.randint(1, pow(10, 9)) for i in range(N)]
    random.shuffle(arr)
    print(arr)
    with open("test.txt", "w") as file:
        file.write(f"{N}\n")
        file.write(f"{' '.join(map(str, arr))}\n")

    os.system("E.exe < test.txt > out1.txt")

    if not check("out1.txt", calc(arr)): quit()
