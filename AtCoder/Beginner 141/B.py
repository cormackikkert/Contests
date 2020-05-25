S = input()
for i, c in enumerate(S):
    if i % 2 == 0:
        if c not in {"R", "U", "D"}:
            print("No")
            quit()
    else:
        if c not in {"L", "U", "D"}:
            print("No")
            quit()

print("Yes")
