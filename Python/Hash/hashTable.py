class HashTable:
    def __init__(self, size):
        if size < 1:
            raise ValueError("Size must be a positive number")
        self.size = size
        self.data = [[] for _ in range(size)]

    def _hash(self, key):
        return key % self.size

    def put(self, key, item):
        position = self.data[self._hash(key)]
        for i in range(len(position)):
            if position[i][0] == key:
                position[i][1] = item
                return
        position.append([key, item])

    def show(self):
        for i in range(len(self.data)):
            if self.data[i] != []:
                print(self.data[i])

    def get(self, key):
        position = self.data[self._hash(key)]
        for i in range(len(position)):
            if position[i][0] == key:
                return print(f"{position[i]} = True")
        print(f"{key} Object not fund = False")

    def remove(self, key):
        position = self.data[self._hash(key)]
        for i in range(len(position)):
            if position[i][0] == key:
                print(f"{position[i]} was removed from the hash")
                return position.pop(i)
        return print("Item is not on the hash table!")

    def free(self):
        self.data = []
        return print("Hash table is empty")