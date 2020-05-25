f,c=open("chairsin.txt").readlines();C,N,K=map(int,f.split())
t=1e7;l=0;h=-1;p=[0,0]
while h<C:
 if N-min(K,p[1])>p[0]:h+=1;p[c[h*(h<C)]>'v']+=1
 else:t=min(h-~-l,t);p[c[l]>'v']-=1;l+=1
open("chairsout.txt","w").write(`t`)