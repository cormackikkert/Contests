"""
ID: cormac.1
TASK: ratios
LANG: PYTHON3
"""

with open("ratios.in") as file:
    gx, gy, gz = map(int, file.readline().split())
    m1x, m1y, m1z = map(int, file.readline().split())
    m2x, m2y, m2z = map(int, file.readline().split())
    m3x, m3y, m3z = map(int, file.readline().split())

def solve():
    for i in range(100):
        for j in range(100):
            for k in range(100):
                if (i == j == k == 0): continue
                if (i * m1x + j * m2x + k * m3x) % gx != 0: continue
                mult = (i * m1x + j * m2x + k * m3x) // gx
                if gy * mult == (i * m1y + j * m2y + k * m3y) and gz * mult == (i * m1z + j * m2z + k * m3z):
                    return (i, j, k, mult)

with open("ratios.out", "w") as file:
    result = solve()
    if result == None:
        file.write("NONE\n")
    else:
        file.write(" ".join(map(str, result)) + "\n")
