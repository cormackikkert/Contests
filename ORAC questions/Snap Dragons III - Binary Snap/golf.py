h=set();p=t=0
for c in map(int,open("snapin.txt").readlines()[1:]):
 if c in h:h=[set([p]),h][p==c];t+=1
 h.add(c);p=c
open("snapout.txt","w").write(`t`)
