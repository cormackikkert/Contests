inn = "clocks.in"
outn = "clocks.out"
inf=open(inn);outf = open(outn,"w");fileInput=lambda:inf.readline().strip();filePrint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

clocks = []
clocks.extend(list(map(int, fileInput().split())))
clocks.extend(list(map(int, fileInput().split())))
clocks.extend(list(map(int, fileInput().split())))

# MOVES
# A B C D E F G H I
# 0 1 2 3 4 5 6 7 8
moves = [[1, 1, 0, 1, 1, 0, 0, 0, 0],
         [1, 1, 1, 0, 0, 0, 0, 0, 0],
         [0, 1, 1, 0, 1, 1, 0, 0, 0],
         [1, 0, 0, 1, 0, 0, 1, 0, 0],
         [0, 1, 0, 1, 1, 1, 0, 1, 0],
         [0, 0, 1, 0, 0, 1, 0, 0, 1],
         [0, 0, 0, 1, 1, 0, 1, 1, 0],
         [0, 0, 0, 0, 0, 0, 1, 1, 1],
         [0, 0, 0, 0, 1, 1, 0, 1, 1]]


# GREEDY

move_clocks = lambda clocks, move: tuple([(clocks[i] + move[i]) % 4 for i in range(len(move))])

start = tuple(clocks)
while start != (0, 0, 0, 0, 0, 0, 0, 0, 0):
    start = max([move_clocks(start, move) for move in moves], key=lambda n:sum(num == 0 for num in n))
    print(start)

print(move)

#filePrint([i+1 for i in paths[(0, 0, 0, 0, 0, 0, 0, 0, 0)]])

        
