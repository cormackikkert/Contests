a = int(open("moobuzz.in").read())
def res(N):
    return ((N-1)//8) * 15 + [1, 2, 4, 7, 8, 11, 13, 14][(N-1)%8]

for i in range(20):
    print(i, res(i))
with open("moobuzz.out", "w") as file:
    ans = res(a)
    file.write(str(ans))