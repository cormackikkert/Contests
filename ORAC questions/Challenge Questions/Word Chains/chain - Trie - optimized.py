def make_trie(words):
    root = dict()
    for word in words:
        current = root
        for letter in word:
            current = current.setdefault(letter, {})
        current['.'] = -1
    return root

with open("chains.in") as file:
    trie = make_trie(iter(lambda: file.readline().strip(), "."))        

queue = [(start, trie[start], 0, start, None) for start in trie.keys()]


maxNode = '.'
maxNodeNum = 0

parent = {}

while queue:
    start, childs, depth, string, last_word = queue.pop(0)

    if '.' in childs:
        depth += 1
        parent[string] = last_word
        last_word = string
        
    if depth > maxNodeNum:
        maxNode = string
        maxNodeNum = depth

    for prefix in childs:
        if prefix != '.':
            queue.append((prefix, childs[prefix], depth, string + prefix, last_word))

words = []
current = maxNode
while parent[current] != None:
    words.append(current)
    current = parent[current]
words.append(current)

with open("chains.out", "w") as file:
    file.write('\n'.join(reversed(words)))

    
