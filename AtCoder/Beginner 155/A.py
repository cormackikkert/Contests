A, B, C = map(int, input().split())

if (len(set({A, B, C})) == 2):
    print("Yes")
else:
    print("No")