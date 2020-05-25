def pref(a, b):
    if a[-1] == "(" and b[-1] == "(":
        a.pop(); b.pop();
        return "("
    if a[-1] == "(" and b[-1] == ")":
        a.pop(); b.pop()
        return "()"
    if a[-1] == ")" and b[-1] == "(":
        a.pop(); b.pop();
        return "()"
    else:
        a.pop(); b.pop();
        return ")"

a = list(reversed(input()))
b = list(reversed(input()))
r = []
while True:
    if a != [] and b != []:
        r += pref(a, b)
    else:
        r += a
        r += b
        break
    print("".join(r), "".join(reversed(a)), "".join(reversed(b)))
    if a == [] and b == []: break
print("".join(r))
