# n = int(input())
digits = "0123456789"
ops = "+*-"

def calc(ex):
    invalid = []
    for k in range(len(ex)):
         if (ex[k] in digits):
             invalid.append(ex[k])
    prex = ""
    sux = ""
    dam = ""
    for j in range(len(ex)):
        if(ex[j]=="="):
            prex = ex[:j]
            sux = ex[j+1:]
    
    for j in range(10):
        if (str(j) in invalid):
            continue  
        prep = prex.replace("?", str(j))
        prux = sux.replace("?", str(j))
        for k in range(1, len(prep)):
            if(prep[k] in ops):
                dam = prep[k+1:]
                break
        if (prep[0:2]=="-0" or prux[0:2]=="-0" or dam[0:2]=="-0"):
            continue
        yes = False
        try:
            yes = eval(prep)==eval(prux)
        except:
            pass
        if (yes):
            return (j)
            break
    else:
        return (-1)


# for i in range(n):
#     print(calc(input()))
    
