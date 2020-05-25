inn = "spiesin.txt"
outn = "spiesout.txt"
inf=open(inn);outf = open(outn,"w");iinput=lambda:inf.readline().strip();
pprint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

N = int(iinput())
XS = [None for i in range(N)]
YS = [None for i in range(N)]
for i in range(N):
    a, b = map(int, iinput().split())
    XS[i] = a
    YS[i] = b
XS.sort()
YS.sort()
pprint([XS[N//2], YS[N//2]])
