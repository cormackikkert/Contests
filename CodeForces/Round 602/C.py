# ))()()()((
# ()))()()((
# ()()))()((
# ()()()))((
# ()()()())(
# ()()()()()

ins = []
def operate(string, l, r):
    global ins
    ins.append((l, r))
    return string[:l] + "".join(map(str, reversed(string[l:r+1]))) + string[r+1:]

def increase(s):
    start = 0
    while s[start] + s[start+1] == "()":
        start += 2
        
    for i in range(start+1, len(s)):
        if s[i] == ")":
            return operate(s, start+1, i)
    
def decrease(s):
    for i in range(1, len(s)):
        if s[i-1] == ")" and s[i] == "(":
            return operate(s, i-1, i)

def count(s):
    c = 0
    su = 0
    for i in range(len(s)):
        if s[i] == "(": su += 1
        else: su -= 1
        if su == 0: c += 1
    return c
            

T = int(input())
for i in range(T):
    ins = []
    N, K = map(int, input().split())
    s = input()

    while True:
        l = 0
        while l < N and s[l] == "(": l += 1
        if l == N:
            break
        r = l + 1
        while r < N and s[r] == ")": r += 1
        if r == N:
            break
        
        s = operate(s, l, r)

    for i in range(K - 1):
       s = increase(s)

    print(len(ins))
    for a, b in ins:
        print(a + 1, b+1)
        

