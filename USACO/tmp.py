with open("rental.in") as file:
    N, M, R = map(int, file.readline().split())
    cows = sorted([int(file.readline()) for i in range(N)])
    stores = [list(map(int, file.readline().split())) for i in range(M)]
    neighs = sorted([int(file.readline()) for i in range(R)])

total_money = 0

stores = sorted(stores, key=lambda n:n[1])

curr_n = R - 1
curr_s = M - 1

def store_mon(milk, x, curr_s):
    total_mon = 0
    while milk > 0:
        used = min(x[curr_s][0], milk)
        total_mon += used * x[curr_s][1]
        
        x[curr_s][0] -= used
        milk -= used
        if x[curr_s][0] <= 0:
            curr_s -= 1
    return total_mon

lo = 0
hi = N - 1

store_money = store_mon(cows[hi], stores, curr_s)
while lo <= hi:
    neigh_money = neighs[curr_n]
    if neigh_money >= store_money:
        total_money += neigh_money
        curr_n -= 1
        lo += 1

    else:
        total_money += store_money
        hi -= 1
        store_money = store_mon(cows[hi], stores, curr_s)

with open("rental.out", "w") as file:
    file.write("{}\n".format(total_money))
