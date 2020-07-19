
A, B, C = map(int, input().split())
D, E, F = map(int, input().split())
G, H, I = map(int, input().split())

inverse = [[3, 2, 3, 2, 2, 1, 3, 1, 0],
           [3, 3, 3, 3, 3, 3, 2, 0, 2],
           [3, 2, 3, 1, 2, 2, 0, 1, 3],
           [3, 3, 2, 3, 3, 0, 3, 3, 2],
           [3, 2, 3, 2, 1, 2, 3, 2, 3],
           [2, 3, 3, 0, 3, 3, 2, 3, 3],
           [3, 1, 0, 2, 2, 1, 3, 2, 3],
           [2, 0, 2, 3, 3, 3, 3, 3, 3],
           [0, 1, 3, 1, 2, 2, 3, 2, 3]]


result = [sum(map(lambda a:a[0]*a[1], zip(row, [4 - A, 4 - B, 4 - C, 4 - D, 4 - E, 4 - F, 4 - G, 4 - H, 4 - I]))) for row in inverse]
moves = [str(i+1)*(item%4) for i, item in enumerate(result)]
print(list(''.join(moves)))