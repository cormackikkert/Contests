# has (string, card)
# if card == string[0]:
#   values += [without(string[1:])]
# elif card == string[1]
#   values += [without(string[0] + string[2:])]
# values += [has(string[1:], string[0]), has(string[0] + string[2:], string[1])]
# return max(values)
#
# without (string)
# return max(has

with open("snapin.txt") as file:
    string = file.read().replace('\n','')

def dp(string, card=None):
    # Base cases:
    if card:
        if len(string) == 1:
            return string[0] == card
        if len(string) == 2:
            return max([string[0] == string[1], string[0] == card, string[1] == card])
    else:
        if len(string) == 2:
            return string[0] == string[1]
        elif len(string) == 1:
            return 0
    
    values = []
    if card:
        if card == string[0]:
            values += [1 + dp(string[1:])]
        elif card == string[1]:
            values += [1 + dp(string[0] + string[2:])]

    values += [dp(string[1:], string[0]), dp(string[0] + string[2:], string[1])]
    # print(string, card, max(values))
    return max(values)

print(dp(string[1:]))
