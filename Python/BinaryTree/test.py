class Node:
    def __init__(self, data):
        self.right = None
        self.left = None
        self.data = data

class BinaryTree:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        if self.root == None:
            return True
        return False

    def insert(self, data):
        node = Node(data)
        if self.isEmpty():
            self.root = node
            return
        if data < self.root:
            self.insert(node.left)
        else:
            if self.right == None:
                self.right = BinaryTree(data)
            else:
                self.right.insert(data)

    # def insert(self, data):
    #     if self.isEmpty():
    #         self.data = data
    #         return
    #     if data > self.data:
    #         self.right.insert(data)
    #     else:
    #         self.left.insert(data)

tree = BinaryTree(3)

print(tree.isEmpty())

# tree.insert(3)
tree.insert(4)
tree.insert(7)
tree.insert(2)
tree.insert(5)
tree.insert(1)
