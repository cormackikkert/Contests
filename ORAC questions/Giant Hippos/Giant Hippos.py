with open("hippoin.txt") as file:
    tulips, hippos, fences = [int(x) for x in file.readline().split()]
    lines = file.readlines()
    outer = [int(lines[0]) - 1, tulips - int(lines[-1])]
    inner = [int(lines[i]) - int(lines[i-1])-1 for i in range(1, hippos)]

high = sum(sorted(inner)[::-1][:fences//2])
if fences % 2:
    high = max(high, sum(sorted(inner[-len(inner):-1])[::-1][:fences//2]) + max(outer[0], outer[-1]))

with open("hippoout.txt", "w+") as file:
    file.write(str(high))
