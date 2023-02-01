class Object:
    def __init__(self, data = None):
        self.data = data

class BinaryTree:
    def __init__(self, data = None):
        if data:
            self.right = None
            self.left = None
            self.data = data
        else:
            self.right = None
            self.left = None
            self.data = None

    def isEmpty(self):
        if self.data == None:
            return True
        return False

    def insert(self, data):
        if self.isEmpty():
            self.data = data
            return
        if data < self.data:
            if self.left == None:
                self.left = BinaryTree(data)
            else:
                self.left.insert(data)
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

tree = BinaryTree()

print(tree.isEmpty())

tree.insert(3)
tree.insert(4)
tree.insert(7)
tree.insert(2)
tree.insert(5)
tree.insert(1)
