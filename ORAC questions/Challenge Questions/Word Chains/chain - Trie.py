with open("chains.in") as file:
    words = list(iter(lambda: file.readline().strip(), "."))

class Node:
  def __init__(self, prefix=''):
    self.prefix = prefix
    self.word = False
    self.childs = []
  
  def add_word(self, word, depth=0):
    if len(word[depth:]) == 1:
      if word in [node.prefix for node in self.childs]:
        for node in self.childs:
          if node.prefix == word:
            node.word = True
      else:
        new = Node(word)
        new.word = True
        self.childs.append(new)
    else:
      for child in self.childs:
        if child.prefix == word[:depth + 1]:
          child.add_word(word, depth + 1)
          break
      else:
        new = Node(word[:depth + 1])
        self.childs.append(new)
        new.add_word(word, depth + 1)
        
root = Node('')

for word in words:
    root.add_word(word)

# Find longest path in Trie
queue = [(root, 0)]
done = []

maxNode = root
maxNodeNum = 0

while queue:
    item, depth = queue.pop(0)

    if depth > maxNodeNum:
        maxNode = item
        maxNodeNum = depth
        
    for prefix in item.childs:
        if prefix not in done:
            queue.append((prefix, depth + prefix.word))

words = []
current = root.childs

word = xNode.prefix

for letter in maxNode.prefix:
    for child in current:
        if child.prefix == letter:
            current = child.childs
            if child.word:
                words.append(child.prefix)

with open("chains.out", "w") as file:
    file.write('\n'.join(reversed(words)))
    
