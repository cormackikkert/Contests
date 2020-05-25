N = int(input())
S = input()
f = ""
for c in S:
    f += chr(((ord(c) - ord("A") + N) % 26) + ord("A"))
print(f)
