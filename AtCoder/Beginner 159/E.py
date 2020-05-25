def gen(start):
    if start == 10:
        return [[]]
    ans = []
    for i in range(start, 10):
        for opt in gen(i+1):
            ans.append([[start, i]] + opt)
    return ans

print(str(gen(0)).replace("[", "{").replace("]", "}"))