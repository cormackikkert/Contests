N, M = map(int, input().split())
AS = list(map(int, input().split()))

import math

buckets = [[] for i in range(31)]
count = [0 for i in range(31)]
for num in AS:
    buckets[math.floor(math.log(num)/math.log(2))].append(num)
    
for lst in buckets: lst.sort(reverse=True)

hi = 30
while buckets[hi-1] == []: hi -= 1
found = 0
while True:
    try:
        if M > found:
            for i in range(hi, 31):
                count[i] += 1
            hi -= 1
            M -= found
            found += len(buckets[hi])
        else:
            total = 0
            for i in range(hi):
                total += sum(buckets[i])
                
            lst = []
            for i in range(hi, 30):
                for item in buckets[i]:
                    lst.append(item // pow(2, count[i]))
             
            lst.sort(reverse=True)
            
            for i in range(M):
                lst[i] //= 2

            total += sum(lst)

            print(total)
            break
    except:
        print(0)
        break
