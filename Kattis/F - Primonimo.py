n, m, p = map(int, input().split())
board = [list(map(int, input().split())) for i in range(n)]

def play(x, y):
    for i in range(m):
        board[y][i] = (board[y][i] + 1) % p
    for i in range(n):
        board[i][x] = (board[i][x] + 1) % p

def unplay(x, y):
    for i in range(m):
        board[y][i] = (board[y][i] - 1) % p
    for i in range(n):
        board[i][x] = (board[i][x] - 1) % p
        
def bruteForce(x, y):
    if y == n:
        if check(board):
            print(
        for i in range(n):
            for j in range(m):
                if board[i][j] != (p - 1):
                    break
    for i in range(p):
        for j in range(i):
            play(x, y)
        bruteForce((x + 1) % m, y + ((x + 1) % m == 0))
        for j in range(i):
            unplay(x, y)
