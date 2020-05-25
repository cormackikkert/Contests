with open("artin.txt") as file:
    BLOCKS = int(file.readline())

    stack = []
    max_height = 0

    for i in range(BLOCKS):
        
        time,*block = map(int, file.readline().split())
        
        while stack and stack[-1][0] <= time:
            height -= stack.pop()[0]
            
        stack += (time + block[0], block[1])
        
        height = len(stack)
        if height > max_height:
            max_height = height
            
with open("artout.txt", "w") as file:
    file.write(str(max_height))
