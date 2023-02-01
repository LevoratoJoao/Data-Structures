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
    #     newNode = Node(data)
    #     if self.isEmpty():
    #         self.root = newNode
    #         return True
    #     if self.root == data:
    #         print("Duplicate data, please insert again")
    #     currentNode = self.root
    #     while True:
    #         if currentNode.data < data:
    #             if currentNode.right == None:
    #                 currentNode.right = newNode
    #                 return
    #             else:
    #                 currentNode = currentNode.right
    #         else:
    #             if currentNode.left == None:
    #                 currentNode.left = newNode
    #                 return
    #             else:
    #                 currentNode = currentNode.left

    def preOrder(self):
        if self.isEmpty():
            return
        print(self.data)
        if self.left is not None:
            self.left.preOrder()
        if self.right is not None:
            self.right.preOrder()

    def posOrder(self):
        if self.isEmpty():
            return
        if self.left is not None:
            self.left.posOrder()
        if self.right is not None:
            self.right.posOrder()
        print(self.data)

    def inOrder(self):
        if self.isEmpty():
            return
        if self.left is not None:
            self.left.inOrder()
        print(self.data)
        if self.right is not None:
            self.right.inOrder()

    def search(self, data):
        if self.data == None:
            return False
        if self.data == data:
            return True
        elif data > self.data:
            if self.right is not None:
                return self.right.search(data)
            else:
                return False
        else:
            if self.left is not None:
                return self.left.search(data)
            else:
                return False

    def maxNode(self):
        if self.right == None:
            ret = self
            self = self.left
            return ret
        return self.right.maxNode()

    def minNode(self):
        if self.left == None:
            ret = self
            self = self.right
            return ret
        return self.left.maxNode()

    def delete(self, node):
        if self.data == None:
            return
        if self.data == node:
            if self.left == None and self.right != None:
                self = self.right
                return self
            elif self.left == None and self.right == None:
                self = None
                return self
            elif self.right == None and self.left != None:
                self = self.left
                return self
            else:
                temp = self.right.minNode()
                self.data = temp.data
                self.right = self.right.delete(temp.data)
                return self
        if node > self.data:
            self.right = self.right.delete(node)
            return self
        else:
            self.left = self.left.delete(node)
            return self