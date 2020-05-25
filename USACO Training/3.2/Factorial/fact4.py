"""
ID: cormac.1
LANG: PYTHON3
TASK: fact4
"""

with open("fact4.in") as file:
    N = int(file.readline())

digit = 1
for i in range(1,N+1):
    digit *= i
    while digit % 10 == 0: digit //= 10
    digit %= 10000

with open("fact4.out", "w") as file:
    file.write(str(digit%10)+"\n")
