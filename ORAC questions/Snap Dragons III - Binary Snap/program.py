def longsight(string, counter):
    if len(string) == 1:
        return counter
    elif len(string) == 2:
        return counter + (string[0] == string[1])
    
    array = [string]
    while True:
        if len(array) == 0:
            return counter
        temp_string = array.pop(0)
        value = shortsight(temp_string)
        if value[0]:
            break
        else:
            for item in value[1]:
                if item:
                    array.append(item)
    '''if len(value[1]) == 1:
        return counter
    else:'''
    return longsight(value[1], counter+1)

def shortsight(string):
    if len(string) <= 2:
        return (False, '')
    elif string[0] == string[2]:
        return (True, [string[1]]+string[3:])
    elif string[0] == string[1]:
        return (True, string[2:])
    else:
        return (False, [[string[0]]+string[2:], string[1:]])
    
with open("snapin.txt") as file:
    string = list([int(line) for line in file.readlines()[1:]])
with open("snapout.txt", "w+") as file:
    ans = longsight(string[1:], 0)
    print(ans)
    file.write(str(ans))
