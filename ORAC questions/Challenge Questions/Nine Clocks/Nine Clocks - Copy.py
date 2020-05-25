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


def should_do(clocks, move):
    for i in range(len(move)):
        if clocks[i] == 0 and move[i] == 1:
            return False
    return True

move_clocks = lambda clocks, move: tuple([(clocks[i] + move[i]) % 4 for i in range(len(move))])

    
# BFS search
queue = [tuple(clocks)]
paths = {tuple(clocks): []}
found = False
while queue and found == False:
    item = queue.pop(0)
    for i, move in enumerate(moves):
        '''if not should_do(clocks, move):
            continue'''
        new_item = move_clocks(item, move)
        if new_item not in paths:
            paths[new_item] = paths[item] + [i]
            if sum(new_item) == 0:
                found = True
                break
            queue.append(new_item)
            
filePrint([i+1 for i in paths[(0, 0, 0, 0, 0, 0, 0, 0, 0)]])

        
