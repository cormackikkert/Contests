with open("balancein.txt") as f:
    cargo = [int(item) for item in f.readlines()[1].split()]
r = 0
l = len(cargo) - 1
timer = 0
while r < l:
    if cargo[r] == cargo[l]:
        pass
    else:
        rtotal = cargo[r]
        ltotal = cargo[l]
        while rtotal != ltotal and r < l:
            if rtotal < ltotal:
                r += 1
                rtotal += cargo[r]
            else:
                l -= 1
                ltotal += cargo[l]
            timer += 1
    r += 1
    l -= 1
        
file = open("balanceout.txt", "w+")  
file.write(str(timer))
        
