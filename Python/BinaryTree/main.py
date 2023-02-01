from binaryTree import BinaryTree

tree = BinaryTree()

print(tree.isEmpty())

tree.insert(7)
tree.insert(4)
tree.insert(6)
tree.insert(2)
tree.insert(3)
tree.insert(5)
tree.insert(8)
tree.insert(1)
tree.insert(9)

print("Pre Order:")
tree.preOrder()
print("Pos Order:")
tree.posOrder()
print("In Order:")
tree.inOrder()

print(tree.search(5))

tree.delete(7)
print("Pre Order:")
tree.preOrder()

tree.delete(6)
print("Pre Order:")
tree.preOrder()

tree.delete(8)
print("Pre Order:")
tree.preOrder()

tree.delete(4)
print("Pre Order:")
tree.preOrder()

tree.free()
print("Pre Order:")
tree.preOrder()
