def split(string):
    if (string == ""):
        return ["",]
    res = []
    for i in range(1, len(string)+1):
        off = split(string[i:])
        for g in off:
            f = []
            f.append(string[:i])
            for x in g:
                f.append(x)
            res.append(f)
    return res

from subprocess import check_output

import os

gay = "()" * pow(10, 6)
l = 0
res = []
for i in [11, 1007, 100011, pow(10, 6) - 5,2 * pow(10, 6)]:
    res.append(gay[l:i])
    l = i

with open("test.txt", "w") as file:
    file.write(str(len(res)) + "\n")
    for x in res:
        file.write(x + "\n")

os.system("F.exe < test.txt > output.txt")
print((open("output.txt").read()).strip())

"""
for lst in split(res):
    with open("test.txt", "w") as file:
        file.write(str(len(lst)) + "\n")
        for x in lst:
            file.write(x + "\n")

    os.system("F.exe < test.txt > output.txt")
    if (open("output.txt").read()).strip() != "Yes": quit()
print("YIPPEE")
"""