with open("chimin.txt") as file:
    length = int(file.readline().strip())
    lion = file.readline().strip()
    snake = file.readline().strip()
    goat = file.readline().strip()

def f(s):
    cur_len = len(s)
    if cur_len == length:
        return min([list.count([s[i] == animal[i] for i in range(length)], True) for animal in (lion,snake,goat)])
    return max(f(s + i) for i in set((lion[cur_len], snake[cur_len], goat[cur_len])))

with open("chimout.txt", "w") as file:
    file.write(str(f("")))
