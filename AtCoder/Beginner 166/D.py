X = int(input())
for i in range(0, 500):
    for j in range(0, 500):
        if i*i*i*i*i-j*j*j*j*j == X:
            print(i, j)
            quit()
        if i*i*i*i*i+j*j*j*j*j == X:
            print(i, -j)
            quit()