N = int(input())
words = input().split()

curPhrase = words[0]

val = {}
for i, c in enumerate("ABCDEFGHIJKLMNOPQRSTUVWXYZ"):
    val[c] = i
for i, c in enumerate("abcdefghijklmnopqrstuvwxyz"):
    val[c] = 26 + i
for i, c in enumerate("0123456789"):
    val[c] = 52 + i
    
def getNum(word):
    total = 0
    for i, c in enumerate(reversed(word)):
        total += val[c] * 62 ** c
for i in range(1, N):
    for j in range(0 
