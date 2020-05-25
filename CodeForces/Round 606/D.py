t = int(input())
for i in range(t):
    n = int(input())
    words = [input() for i in range(n)]

    s01 = []
    s10 = []
    set01 = set()
    set10 = set()
    s00 = False
    s11 = False
    for i, word in enumerate(words):
        if word[0] == "1" and word[-1] == "0": s10.append(i+1); set10.add(word)
        if word[0] == "0" and word[-1] == "1": s01.append(i+1); set01.add(word)
        if word[0] == "0" and word[-1] == "0": s00 = True
        if word[0] == "1" and word[-1] == "1": s11 = True
    
    s01c = len(s01)
    s10c = len(s10)

    if (s01c + s10c == 0) and s00 and s11:
        print(-1)
        continue
    
    reverse = []
    try:
        while True:
            if abs(s01c - s10c) <= 1: break

            if s01c > s10c:
                i = s01.pop()
                while words[i-1][::-1] in set10: i = s01.pop(); 
                s01c -= 1;
                s10c += 1;
                reverse.append(i)
            else:
                i = s10.pop()
                while words[i-1][::-1] in set01: i = s10.pop()
                s01c += 1;
                s10c -= 1;
                reverse.append(i)
    except:
        print(-1)
    print(len(reverse))
    print(" ".join(map(str, reverse)))
        
