S = input()
S = S.replace("BC", "X")
ans = 0
lo = 0
while True:
    while lo < len(S) and (S[lo] == "B" or S[lo] == "C"): lo += 1
    if lo == len(S): break
    hi = lo
    X = 0
    while hi < len(S) and S[hi] != "B" and S[hi] != "C":
        if S[hi] == "X": 
            ans += hi - lo
            lo += 1 
        hi += 1
    lo = hi
print(ans)
    
