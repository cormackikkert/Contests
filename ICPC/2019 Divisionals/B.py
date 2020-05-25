line = input().strip("0")

A = 0 # 101...
B = 0 # 010...

for c in line:
    if c == "1":
        A += B + 1
    else:
        B += A

    A %= 1000000007
    B %= 1000000007
        
print((A - line.count("1")) % 1000000007)
