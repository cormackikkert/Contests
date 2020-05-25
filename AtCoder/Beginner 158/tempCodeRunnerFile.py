n = random.randint(1, 100)
        s = 3
        file.write(f"{n} {s}\n")
        file.write("".join([str(random.randint(0, 9)) for i in range(n)]))