import itertools

n=3
for LION in itertools.product("AGCT", repeat=3):
    for SNAKE in itertools.product("AGCT", repeat=3):
        for GOAT in itertools.product("AGCT", repeat=3):
            lion = list(LION)
            snake = list(SNAKE)
            goat = list(GOAT)
            seq = [list(LION), list(SNAKE), list(GOAT)]
            length = 3

            def f(s):
                cur_len = len(s)
                if cur_len == length:
                    return min([list.count([s[i] == animal[i] for i in range(length)], True) for animal in (lion,snake,goat)])
                return max(f(s + i) for i in set((lion[cur_len], snake[cur_len], goat[cur_len])))

            res1 = f("")
            # print(LION, SNAKE, GOAT, "Passed")

