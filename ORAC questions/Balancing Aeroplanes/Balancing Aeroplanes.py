with open("balancein.txt") as f:
    cargo = [int(item) for item in f.readlines()[1].split()]
    print(cargo)
    print("Done")
