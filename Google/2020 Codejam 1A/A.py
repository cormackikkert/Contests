def good(batch):
    last = ""
    for s in batch:
        if s[::-1][:len(last)][::-1] != last:
            return False
        last = s
    return True

def good2(batch):
    last = ""
    for s in batch:
        if s[:len(last)] != last:
            return False
        last = s
    return True
    
def solve():
    N = int(input())
    SS = [input() for i in range(N)]
    cur = [0 for i in range(N)]
    # for i in range(N):
    #     while cur[i] < len(SS[i]) and SS[i][cur[i]] == '*': cur[i] += 1

    arr = list(cur)
    for i in range(N):
        while arr[i] < len(SS[i]) and SS[i][arr[i]] != '*': arr[i] += 1
    
    batch = [SS[i][:arr[i]] for i in range(N)]
    batch.sort(key=len)
    ans = ""
    if (good2(batch)):
        ans = batch[-1]
        medumb = [SS[i][arr[i]:].split("*") for i in range(N)]
        batch = [medumb[i][-1] for i in range(N)]
        batch.sort(key=len)
        if (good(batch)):
            for i in range(N):
                for s in range(len(medumb[i])-1):
                    ans += medumb[i][s]
            ans += batch[-1]
            return ans
        else:
            return "*"
    else:
        return "*"
    


        # cur = list(arr)
        # for i in range(N):
        #     arr[i]+=1
        #     while arr[i] < len(SS[i]) and SS[arr[i]] != '*': arr[i] += 1
        # break

T = int(input())
for i in range(T):
    print("Case #"+str(i+1)+": "+solve())