from avlTree import AvlTree

avlTree = AvlTree()

avlTree = avlTree.insert(5)
print("Pre order")
avlTree.preOrder()

avlTree = avlTree.insert(6)
avlTree = avlTree.insert(9)
print("Pre order")
avlTree.preOrder()
avlTree = avlTree.insert(16)
avlTree = avlTree.insert(14)
avlTree = avlTree.insert(17)
avlTree = avlTree.insert(15)
print("Pre order")
avlTree.preOrder()

avlTree = avlTree.insert(4) ### bug here - sometimes when u want to insert something it requires a return

# avlTree = avlTree.insert(5) ## bug here - dont know why but it doesnt insert properly
print("Pre order")
avlTree.preOrder()

avlTree = avlTree.delete(16)
print("Pre order")
avlTree.preOrder()

# avlTree = avlTree.delete(4) ## bug here - infinity recursion
print("Pre order")
avlTree.preOrder()

