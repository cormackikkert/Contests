import re
input()
print(max([len(set(s))for s in re.findall('[a-z]+',input())]+[0]))
