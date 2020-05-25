
def isValid(string):
    for i in range(1, len(string)):
        if string[i] == string[i-1]: return False
    return True

def get_moves(string):
    res = []
    for i in range(1, len(string) - 1):
        if isValid(string[:i]+string[i+1:]): res.append(string[:i]+string[i+1:])
    return res

from itertools import product

isWinning = set()

for length in range(3, 8):
    for s in product(list("abcde"), repeat=length):
        string = "".join(s)
        if not isValid(string): continue
        for move in get_moves(string):
            if not move in isWinning: isWinning.add(string)
        if not string in isWinning: print(string)

"""

for item in sorted(isWinning, key=lambda x : len(x)):
    print(item)
"""