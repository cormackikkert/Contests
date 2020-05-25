with open("work.in") as file:
    with open("work.out", "w") as outf:
        C = int(file.readline())
        for i in range(C):
            
            N, M, L = map(int, file.readline().split())
            outf.write('Case ' + str(i + 1) + '\n')
            scores = []

            for j in range(L):
                # Greedy approach
                agency, _ = file.readline().split(':')
                costA, costB = map(int, _.split(','))
                start, costT = N, 0
                while start > M:
                    if (start >> 1) >= M:
                        if (start - (start >> 1)) * costA > costB:
                            costT += costB
                            start = start >> 1
                        else:
                            costT += costA
                            start = start - 1
                    else:
                        costT += costA
                        start = start - 1
                scores.append((costT, agency))
                
            for score, name in sorted(scores):
                outf.write(name + ' ' + str(score) +'\n')
                
    

    
