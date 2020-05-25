def calc():
    X, Y = map(int, input().split())
    SX = bin(abs(X))[2:][::-1] + "0" * 100
    SY = bin(abs(Y))[2:][::-1] + "0" * 100

    XA = [int(SX[i] == '1') for i in range(60)]
    YA = [int(SY[i] == '1') for i in range(60)]

    for i in range(60):
        if XA[i] != 0 and YA[i] != 0:
            for j in reversed(range(i)):
                if max(XA[i], YA[i]) == 1:
                    break
            else:
                return "IMPOSSIBLE"
            
            if XA[j] == YA[j]:
                return "IMPOSSIBLE"
            
            if XA[j] == 1:
                for k in range(j, i): XA[k] = -1
                XA[i] = 0
                while XA[i+1] == 1:
                    XA[i+1] = 0
                    i += 1
                XA[i+1] = 1
            else:
                for k in range(j, i): YA[k] = -1
                YA[i] = 0
                while YA[i+1] == 1: 
                    YA[i+1] = 0
                    i+=1
                YA[i+1] = 1

    foundX = False
    res = ""
    for i in range(60):
        if XA[i] == 1:
            res += ['W','E'][X>0]
            if foundX: return "IMPOSSIBLE"
        elif XA[i] == -1:
            res += ['W', 'E'][X<0]
            if foundX: return "IMPOSSIBLE"
        elif YA[i] == 1:
            res += 'SN'[Y>0]
            if foundX: return "IMPOSSIBLE"
        elif YA[i] == -1:
            res += 'SN'[Y<0]
            if foundX: return "IMPOSSIBLE"
        else:
            foundX = True
    return res

T = int(input())
for i in range(T):
    print("Case #"+str(i+1)+": " + calc())