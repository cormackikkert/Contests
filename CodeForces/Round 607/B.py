def swap(lst, i, j):
    lst[i], lst[j] = lst[j], lst[i]

def comp(l1, l2):
    for i in range(min(len(l1), len(l2))):
        if l1[i] < l2[i]:
            return True
        if l1[i] == l2[i]:
            continue
        return False
    return len(l1) < len(l2)

def logic(s, c):
    if comp(s, c):
        return s
    best = -1
    for i in reversed(range(len(s))):
        if best == -1 or s[i] < s[best]: best = i
        swap(s, i, best)
        if comp(s, c):
            return s
        swap(s, i, best)
    return list("---")

t = int(input())
for i in range(t):
    s,c = input().split()
    s = list(s)
    c = list(c)
    a = logic(s, c)
    print("".join(a))
        
