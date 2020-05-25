with open("savein.txt") as file:
    cost = sorted(list(map(int, file.readlines()[1:])), key=lambda n: n % 5, reverse = True)

current = 0
total = 0
while current <= len(cost) - 1:
    if cost[current] % 5 <= 2:
        total += cost[current] // 5 * 5
    else:
        num = cost[current] % 5
        temp = current
        while temp < len(cost) - 1 and (num % 5) > 2:
            temp += 1
            num += cost[temp] % 5
        total += sum(cost[current:temp+1]) // 5 * 5
        current = temp
    current += 1

with open("saveout.txt", "w+") as file:
    file.write(str(total))
