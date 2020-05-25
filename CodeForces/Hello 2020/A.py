N, M = map(int, input().split())
SS = input().split()
TS = input().split()
q = int(input())
for i in range(q):
    y = int(input())-1
    print(SS[y%N] + TS[y%M])
    
