def win(s,t):
    moves = "PRSPRS"
    wins = [0,0,0]
    for i in range(k):
        me = moves.find(s[i])
        you = moves.find(t[i],me)
        wins[you-me] += 1
        if you != me and wins[you-me] == m:
            return -1 if you-me == 2 else 1
    return 0

def morph(s,st):
    moves = "RPSR"

    return s[:st] + "".join(list(moves[1+moves.find(s[i])] for i in range(st,st+l))) + s[st+l:]

def phase3(s,t):
    return max(win(morph(s,i),t) for i in range(k-l+1))

def phase2(s,t):
    return min(phase3(s,t[i:i+k]) for i in range(n-k+1))

def phase1(s,t):
    return max(phase2(s[i:i+k],t) for i in range(n-k+1))

n,k,l,m = [int(x) for x in input().split()]

s = input()
t = input()

winner = phase1(s,t)

if winner == 0:
    print("Draw")
else:
    print("Alice" if winner == 1 else "Bob")
