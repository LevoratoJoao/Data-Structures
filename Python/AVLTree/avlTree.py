class AvlTree:
    def __init__(self, data = None, height = None):
        self.left = None
        self.right = None
        self.height = height
        self.data = data

    def maxHeightSon(self):
        if self.left == None and self.right == None:
            return 0
        elif self.left == None:
            return self.right.height
        elif self.right == None:
            return self.left.height
        return self.right.height if self.right.height > self.left.height else self.left.height

    def rotateRight(self):
        temp = self.left
        self.left = temp.right
        temp.right = self
        self = temp
        self.right.height = self.right.maxHeightSon() + 1
        self.height = self.maxHeightSon() + 1
        return self

    def rotateLeft(self):
        temp = self.right
        self.right = temp.left
        temp.left = self
        self = temp
        self.left.height = self.left.maxHeightSon() + 1
        self.height = self.maxHeightSon() + 1
        return self

    @staticmethod
    def heightTree(node):
        if node == None:
            return 0
        return node.height

    def balanceFactor(self):
        if self == None:
            return 0
        return self.heightTree(self.right) - self.heightTree(self.left)

    def rotateTree(self):
        if self.balanceFactor() == 2:
            if self.right.balanceFactor() < 0:
                self = self.right.rotateRight()
            self = self.rotateLeft()
            return self
        elif self.balanceFactor() == -2:
            if self.left.balanceFactor() > 0:
                self = self.left.rotateLeft()
            self = self.rotateRight()
            return self
        return self

    def insert(self, data):
        if self.data == None:
            self.data = data
            self.height = 1
            return
        if self.data > data:
            if self.left == None:
                self.left = AvlTree(data, 1)
            else:
                self.left.insert(data)
        else:
            if self.right == None:
                self.right = AvlTree(data, 1)
            else:
                self.right.insert(data)
        self.height = self.maxHeightSon() + 1
        self = self.rotateTree()
        return self

    def preOrder(self):
        if self.data == None:
            return
        print(self.data)
        if self.left is not None:
            self.left.preOrder()
        if self.right is not None:
            self.right.preOrder()

    def delete(self, data):
        if self.data == None:
            return
        if self.data == data:
            if self.left == None and self.right == None:
                self = None
            elif self.left == None:
                self = self.right
            elif self.right == None:
                self = self.left
            else:
                aux = self
                prev = self
                self = self.left
                while self.right is not None:
                    prev = self
                    self = self.right
                self.right = aux.right
                prev.right = self.left
                if aux != prev:
                    self.left = aux.left
                self.left.height = self.left.maxHeightSon() + 1
                self.right.height = self.right.maxHeightSon() + 1
                self.height = self.maxHeightSon() + 1
                return self
        if self.data < data:
            self.right = self.right.delete(data)
        #  self.data < data
        else:
            self.left = self.left.delete(data)
        self.height = self.maxHeightSon() + 1
        self = self.rotateTree()
        return self