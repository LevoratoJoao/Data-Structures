class BTreeNode:
    def __init__(self, leaf=False):
        self.keys = []
        self.child = []
        self.leaf = leaf

    def insert_non_full(self, key):
        i = len(self.keys) - 1
        if self.leaf:
            self.keys.append(None)
            while i >= 0 and key < self.keys[i]:
                self.keys[i + 1] = self.keys[i]
                i -= 1
            self.keys[i + 1] = key
        else:
            while i >= 0 and key < self.keys[i]:
                i -= 1
            if len(self.child[i + 1].keys) == 2 * t - 1:
                self.split_child(i + 1, self.child[i + 1])
                if key > self.keys[i + 1]:
                    i += 1
            self.child[i + 1].insert_non_full(key)

    def split_child(self, i, y):
        z = BTreeNode(y.leaf)
        self.child.insert(i + 1, z)
        self.keys.insert(i, y.keys[t - 1])
        z.keys = y.keys[t: (2 * t - 1)]
        y.keys = y.keys[0: (t - 1)]
        if not y.leaf:
            z.child = y.child[t: 2 * t]
            y.child = y.child[0: t - 1]

    def traverse(self):
        result = []
        i = 0
        while i < len(self.keys):
            if self.leaf:
                result.append(self.keys[i])
            else:
                result.extend(self.child[i].traverse())
                result.append(self.keys[i])
            i += 1
        if not self.leaf:
            result.extend(self.child[i].traverse())
        return result


class BTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = BTreeNode(leaf=True)
            self.root.keys.append(key)
        else:
            if len(self.root.keys) == (2 * t - 1):
                new_root = BTreeNode()
                new_root.child.append(self.root)
                new_root.split_child(0, self.root)
                i = 0
                if new_root.keys[0] < key:
                    i += 1
                new_root.child[i].insert_non_full(key)
                self.root = new_root
            else:
                self.root.insert_non_full(key)

    def traverse(self):
        if self.root is not None:
            return self.root.traverse()
        else:
            return []


# Teste
t = 3
tree = BTree()

# Inserção de chaves
tree.insert(10)
tree.insert(20)
tree.insert(5)
tree.insert(6)
tree.insert(12)
tree.insert(30)
tree.insert(7)
tree.insert(17)

# Impressão em ordem
print("Chaves na árvore B:")
print(tree.traverse())
