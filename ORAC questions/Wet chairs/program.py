with open("chairsin.txt") as file:
    C, N, K = map(int,file.readline().split())
    chairs = [int(char == 'w') for char in file.readline()]

def p(i, j):
    wet_chairs = sum(chairs[i:j+1])
    dry_chairs = j - i + 1 - wet_chairs
    return dry_chairs + wet_chairs >= K and dry_chairs >= N-K
    
def binary_search(lo, hi, p):
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if p(mid) == True:
            hi = mid
        else:
            lo = mid + 1
    if p(lo) == False:
        return None
    print("Return")
    p(lo)
    return lo

scores = []
for i in range(C):
    score = binary_search(i, C-1, lambda x:p(i,x))
    if score:
        scores.append(score - i + 1)
    else:
        scores.append(None)
print(scores)
with open("chairsout.txt","w+") as file:
    try:
        file.write(str(min([x for x in scores if x])))
    except:
        file.write(str(C))
