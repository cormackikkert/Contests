"""
ID: cormac.1
TASK: heritage
LANG: PYTHON2
"""

import time

with open("heritage.in") as file:
    inorder = file.readline().strip()
    preorder = file.readline().strip()

fout = open("heritage.out", "w")

total = ""

def getTree(inorder, preorder):
    global total
    if preorder == "": return
    root = preorder[0]
    left = ""
    right = ""
    for c in preorder[1:]:
        if inorder.index(c) < inorder.index(root):
            left += c
        else:
            right += c   
    getTree(inorder, left)
    getTree(inorder, right)
    total += root

getTree(inorder, preorder)

fout.write(total + "\n")
fout.close()
