from avlTree import AvlTree

avlTree = AvlTree()

avlTree.insert(10)
print("Pre order")
avlTree.preOrder()

avlTree.insert(3)
avlTree.insert(13)
avlTree.insert(16)
avlTree = avlTree.insert(14)
print("Pre order")
avlTree.preOrder()
avlTree.insert(17)
avlTree.insert(15)


avlTree = avlTree.insert(4) ### bug here - sometimes when u want to insert something it requires a return

# avlTree = avlTree.insert(5) ## bug here - dont know why but it doesnt insert properly
print("Pre order")
avlTree.preOrder()

avlTree = avlTree.delete(16)
print("Pre order")
avlTree.preOrder()

avlTree = avlTree.delete(4) ## bug here - infinity recursion
print("Pre order")
avlTree.preOrder()

