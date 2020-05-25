# seqs = [(1, 0, 0), (0, 1, 0), (0, 0, 1), (1, 1, 0), (1, 0, 1), (0, 1, 1), (1, 1, 1)]

T = int(input())
for i in range(T):
    a, b, c = sorted(list(map(int, input().split())), reverse=True)

    count = 0

    if a > 0:
        a -= 1
        count += 1
    if b > 0:
        b -= 1
        count += 1
    if c > 0:
        c -= 1
        count += 1
    if a > 0 and b > 0:
        a -= 1; b -= 1;
        count += 1
    if a > 0 and c > 0:
        a -= 1; c -= 1;
        count += 1
    if b > 0 and c > 0:
        b -= 1; c -= 1;
        count += 1
    if a > 0 and b > 0 and c > 0:
        count += 1

    print(count)
    