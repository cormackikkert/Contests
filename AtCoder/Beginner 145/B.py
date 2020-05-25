N = int(input())
S = input()
if N % 2 != 0:
    print("No")
    quit()
else:
    if S[:N//2] == S[N//2:]:
        print("Yes")
    else:
        print("No")
