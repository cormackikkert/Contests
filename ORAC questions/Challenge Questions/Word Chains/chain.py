with open("chains.in") as file:
    words = list(iter(lambda: file.readline().strip(), "."))

dp = [0 for i in range(len(words))]
pt = [-1 for i in range(len(words))]

for i in range(len(words)):
    prefs = words[lo:i]
    
    if prefs:
        possibles = [(dp[j], j) for j,word in enumerate(prefs) if word == words[i][:len(word)]]
        if possibles:
            score, index = max(possibles, key = lambda a: a[0])
            dp[i] = 1 + score
            pt[i] = index

wordList = []
current = max(range(len(words)), key = lambda n:dp[n])

while pt[current] != -1:
    wordList.append(words[current])
    current = pt[current]

wordList.append(words[current])

with open("chains.out", "w") as file:
    file.write('\n'.join(reversed(wordList)))
