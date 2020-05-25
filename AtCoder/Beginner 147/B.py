s = input()
i = 0
t = 0
while i < len(s) - 1 - i:
    if s[i] != s[len(s)-1-i]:
        t += 1
    i += 1
print(t)
