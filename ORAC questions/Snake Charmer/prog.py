x,y=map(int,open("snakein.txt").read().split());o=open("snakeout.txt","w");a=b=d=0
while(x-a)|(b-y)!=0:f=d%2;m=[x<a,y<b][f]==d/2;t=1-2*(m==d/2);o.write("LR"[(m+d)%2]);a+=t*(1-f);b+=t*f;d=2-f-t
