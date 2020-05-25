inn = "clocks.in"
outn = "clocks.out"
inf=open(inn);outf = open(outn,"w");fileInput=lambda:inf.readline().strip();
filePrint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

clocks = []
clocks.extend(list(map(int, fileInput().split())))
clocks.extend(list(map(int, fileInput().split())))
clocks.extend(list(map(int, fileInput().split())))

# MOVES
# A B C D E F G H I
# 0 1 2 3 4 5 6 7 8
moves = [[0, 1, 3, 4],
         [0, 1, 2],
         [1, 2, 4, 5],
         [0, 3, 6],
         [1, 3, 4, 5, 7],
         [2, 5, 8],
         [3, 4, 6, 7],
         [6, 7, 8],
         [4, 5, 7, 8]]

move_clocks = lambda clocks, move: tuple([(num + (i in move)) % 4 for i,num in enumerate(clocks)])

    
# BFS search
queue = [(tuple(clocks), (0, 0, 0, 0, 0, 0, 0, 0, 0))]
paths = {(tuple(clocks), (0, 0, 0, 0, 0, 0, 0, 0, 0)): []}
found = False
alter = False
while queue and found == False:
    item1, item2 = queue.pop(0)
    for i, move in enumerate(moves):
        move_list = tuple(sorted(list(paths[(item1, item2)]) + [i]))
        if move_list not in paths:
            new_item1 = move_clocks(item1, move)
            new_item2 = move_clocks(item2, move)
            if (new_item1, new_item2) not in paths:
                paths[(new_item1, new_item2)] = move_list
                if sum(new_item1) == 0:
                    found = True
                    result = move_list
                    break
                elif list(new_item2) == clocks:
                    found = True
                    alter = True
                    result = move_list
                    break
                queue.append((new_item1, new_item2))

if alter:
    s = ''
    for i, number in enumerate([(4 - result.count(i)) % 4 for i in range(9)]):
        for j in range(number):
            s += str(i+1)
    filePrint(list(s))
else:
    filePrint([i+1 for i in move_list])
