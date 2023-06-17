class BTreeNode:
    def __init__(self, leaf=False):
        self.keys = []
        self.child = []
        self.leaf = leaf

    def insertNotFull(self, key, size):
        i = len(self.keys) - 1 # indice da ultima chave
        if self.leaf:
            self.keys.append(None)
            while i >= 0 and key < self.keys[i]: # enquanto o indice for maior ou igual a 0 e a chave for menor que a chave do indice
                self.keys[i + 1] = self.keys[i] # a chave do indice + 1 recebe a chave do indice
                i -= 1
            self.keys[i + 1] = key # a chave do indice + 1 recebe a chave
        else:
            while i >= 0 and key < self.keys[i]: # enquanto o indice for maior ou igual a 0 e a chave for menor que a chave do indice
                i -= 1
            if len(self.child[i + 1].keys) == 2 * size - 1: # se o tamanho da chave do indice + 1 for igual a 2 * o tamanho - 1
                self.splitChild(i + 1, self.child[i + 1], size) # divide o filho do indice + 1
                if key > self.keys[i + 1]:
                    i += 1
            self.child[i + 1].insertNotFull(key, size) # insere a chave no filho do indice + 1

    def splitChild(self, i, y, size):
        z = BTreeNode(y.leaf) # cria um novo no

        self.child.insert(i + 1, z) # insere o novo no no indice + 1
        self.keys.insert(i, y.keys[size - 1]) # insere a chave do meio no indice

        z.keys = y.keys[size: (2 * size - 1)] # as chaves do novo no recebem as chaves do meio + 1 ate o tamanho - 1
        y.keys = y.keys[0: (size - 1)] # as chaves do no recebem as chaves do inicio ate o meio - 1

        if not y.leaf: # se o no nao for folha
            z.child = y.child[size: 2 * size] # os filhos do novo no recebem os filhos do meio ate o tamanho
            y.child = y.child[0: size - 1] # os filhos do no recebem os filhos do inicio ate o meio - 1

    def traverse(self):
        result = []
        i = 0
        while i < len(self.keys):
            if self.leaf:
                result.append(self.keys[i])
            else:
                result.extend(self.child[i].traverse()) # estende a lista com os filhos
                result.append(self.keys[i]) # adiciona a chave
            i += 1
        if not self.leaf:
            result.extend(self.child[i].traverse()) # estende a lista com os filhos
        return result


class BTree:
    def __init__(self, size=0):
        self.root = None
        self.size = size

    def insert(self, key):
        if self.root is None:
            self.root = BTreeNode(leaf=True)
            self.root.keys.append(key)
        else:
            if len(self.root.keys) == (2 * self.size - 1): # se o tamanho da chave for igual a 2 * o tamanho - 1
                newRoot = BTreeNode()
                newRoot.child.append(self.root)
                newRoot.splitChild(0, self.root, self.size) # divide o filho do indice 0
                i = 0
                if newRoot.keys[0] < key: # se a chave do indice 0 for menor que a chave
                    i += 1
                newRoot.child[i].insertNotFull(key, self.size) # insere a chave no filho do indice
                self.root = newRoot # a raiz recebe o novo no
            else:
                self.root.insertNotFull(key, self.size) # insere a chave no no raiz

    def traverse(self):
        if self.root is not None: 
            return self.root.traverse()
        else:
            return []