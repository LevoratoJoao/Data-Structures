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


avlTree = avlTree.insert(4)

avlTree = avlTree.insert(5)
print("Pre order")
avlTree.preOrder()




