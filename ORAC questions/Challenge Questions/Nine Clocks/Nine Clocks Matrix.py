inn = "clocks.in"
outn = "clocks.out"
inf=open(inn);outf=open(outn,"w");fileInput=lambda:inf.readline().strip();
filePrint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

A, B, C = map(int, fileInput().split())
D, E, F = map(int, fileInput().split())
G, H, I = map(int, fileInput().split())

inverse = [[3, 2, 3, 2, 2, 1, 3, 1, 0],
           [3, 3, 3, 3, 3, 3, 2, 0, 2],
           [3, 2, 3, 1, 2, 2, 0, 1, 3],
           [3, 3, 2, 3, 3, 0, 3, 3, 2],
           [3, 2, 3, 2, 1, 2, 3, 2, 3],
           [2, 3, 3, 0, 3, 3, 2, 3, 3],
           [3, 1, 0, 2, 2, 1, 3, 2, 3],
           [2, 0, 2, 3, 3, 3, 3, 3, 3],
           [0, 1, 3, 1, 2, 2, 3, 2, 3]]

result = [sum(map(lambda a:a[0]*a[1], zip(row, [A, B, C, D, E, F, G, H, I]))) for row in inverse]
filePrint(list(''.join([str(i+1)*((4-item)%4) for i, item in enumerate(result)])))

