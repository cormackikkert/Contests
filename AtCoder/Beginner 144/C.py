N = int(input())
moves = float('inf')
for col in range(1, int(N ** 0.5) + 2):
    if N % col != 0: continue
    moves = min(moves, col-1 + N // col-1)
print(moves)
    
    
