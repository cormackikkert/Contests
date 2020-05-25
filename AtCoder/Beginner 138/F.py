L = 10
c = 0
for x in range(64, 101):
    for y in range(x, 101):
        if y % x == y ^ x:
            
            if bin(x).count("1") == 0:
                # print(x, bin(x), bin(y))
                c += 1
print(c)
