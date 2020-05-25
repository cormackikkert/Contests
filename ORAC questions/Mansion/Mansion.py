with open("manin.txt") as file:
    house, width = map(int,file.readline().split())
    houses = [int(file.readline()) for i in range(house)]

value = sum(houses[:width])
highest = value
for i in range(1, house - width + 1):
    value = value - houses[i-1] + houses[i+width-1]
    highest = max(highest, value)

with open("manout.txt", "w+") as file:
    file.write(str(highest))
