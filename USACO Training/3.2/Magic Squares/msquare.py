"""
TASK: msquare
ID: cormac.1
LANG: PYTHON3
"""

with open("msquare.in") as file:
    t = tuple(map(int, file.readline().split()))

target = (t[0], t[1], t[2], t[3], t[7], t[6], t[5], t[4])

seen = set()

def applyA(board):
    return (board[4], board[5], board[6], board[7], board[0], board[1], board[2], board[3])
    
def applyB(board):
    return (board[3], board[0], board[1], board[2], board[7], board[4], board[5], board[6])

def applyC(board):
    return (board[0], board[5], board[1], board[3], board[4], board[6], board[2], board[7])

def search(board):
    queue = [(board, "")]
    while queue:
        board, string = queue.pop(0)
        # print(string)
        if board == target:
            return string

        if (applyA(board) not in seen):
            queue.append((applyA(board), "A"+string))
            seen.add(applyA(board))
            
        if (applyB(board) not in seen):
            queue.append((applyB(board), "B"+string))
            seen.add(applyB(board))
            
        if (applyC(board) not in seen):
            queue.append((applyC(board), "C"+string))
            seen.add(applyC(board))

result = search((1, 2, 3, 4, 8, 7 ,6 ,5))

with open("msquare.out", "w") as file:
    
    file.write(str(len(result)) + "\n")
    file.write(result[::-1] + "\n")
        
