with open("balancein.txt") as f:
    cargo = [int(item) for item in f.readlines()[1].split()]
point = len(cargo) // 2 
rs = sum(cargo[point + 1::])
ls = sum(cargo[:point])
print(cargo)
if rs == ls:
    r = point + 1
    l = point - 1
else:
    if rs < ls:
        direction = -1
    elif ls < rs:
        direction = 1
    while True:
        rs = sum(cargo[point + 1::])
        ls = sum(cargo[:point])

        if rs == ls:
            r = point + 1
            l = point - 1
            break
        
        if direction == 1:
            if (rs == (ls + cargo[point])):
                r = point + 1
                l = point
                break
            elif ls > rs:
                r = False
                break
        else:
            if (ls == (rs + cargo[point])):
                r = point
                l = point - 1
                break
            elif ls < rs:
                r = False
                break
        point += direction
        if (point < 0 or point >= len(cargo)):
            r = False
            break
file = open("balanceout.txt", "w+")  
if  not r:
    file.write(str(len(cargo) - 1))   
else:
    timer = 0
    while True:
        timer += 1
        try:
            while True:
                if cargo[l] == cargo[r]:
                    l -= 1
                    r += 1
                else:
                    break
        except:
            timer = 0
            break
        if cargo[l] < cargo[r]:
            # Add left stack to lr
            cargo[l] += cargo[l - 1]
            cargo.pop(l - 1)
            l -= 1
            r -= 1
        else:
            # Add right stack to rr
            cargo[r] += cargo[r + 1]
            cargo.pop(r + 1)
        print(cargo)
        if (l == 0) and (r == (len(cargo) - 1)):
            break
    file.write(str(timer))
        
