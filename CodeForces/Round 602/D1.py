N = int(input())
AS = list(map(int, input().split()))
M = int(input())

SAS = sorted(range(N), key = lambda x:(AS[x], -x), reverse=True)

for i in range(M):
    k, pos = map(int, input().split())
    print(AS[sorted(SAS[:k])[pos-1]])
