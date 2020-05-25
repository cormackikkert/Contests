t,=open("fibin.txt")
x,y=0,1
for i in xrange(int(t)):x,y=y%1000,x+y
print>>open("fibout.txt","w"),x
