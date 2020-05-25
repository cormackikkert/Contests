with open("snakein.txt") as file:
    N = int(file.readline())
    string = file.readline().strip()

def calc(string):
    dp = [[1, 1, 1, 1, 1] for i in range(100000)]
    S = N = A = K = E = 0
    ST= NT= AT= KT= ET= 0
    for c in string:
        if c == 'S':
            dp[S][0] -= 1
            ST += 1
            if dp[S][0] == 0:
                dp[S][1] = 1+NT; NT=0
                S += 1
                
        elif c == 'N' and dp[N][0] == 0:
            dp[N][1] -= 1
            NT += 1
            if dp[N][1] == 0:
                dp[N][2] = 1+AT; AT=0
                N += 1  
                
        elif c == 'A' and dp[A][1] == 0:
            dp[A][2] -= 1
            AT += 1
            if dp[A][2] == 0:
                dp[A][3] = 1+KT; KT=0
                A += 1
                    
        elif c == 'K' and dp[K][2] == 0:
            dp[K][3] -= 1
            KT += 1
            if dp[K][3] == 0:
                dp[K][4] = 1+ET; ET=0
                K += 1
                
        elif c == 'E' and dp[E][3] == 0:
            dp[E][4] -= 1
            ET += 1
            if dp[E][4] == 0:
                E += 1
    return E

with open("snakeout.txt", "w") as file:
    file.write(str(calc(string)))
