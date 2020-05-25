f=file('bendin.txt')
x,y=map(sorted,[
file('bendout.txt','w').write(`
def f(x1, y1, x2, y2, x3, y3, x4, y4):
    x,y=map(sorted,[[(a,b),(c,d)],[(e,f),(g,h)]])
    if x[1][0]>y[1][0]:y,x=x,y
    w=x[1][0]-y[0][0]
    if x[1][1]>y[1][1]:y,x=x,y
    h=x[1][1]-y[0][1]
    return (c-a)*(d-b)+(g-e)*(h-f)-h*w*(h>0)*(w>0)
