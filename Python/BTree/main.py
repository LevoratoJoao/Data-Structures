from BTree import BTree

if __name__ == "__main__":
    sequence = [-6, -32, 68, 33, -1, 22, 62, -34, 90, -26, -95, 17, 44, 93, 76, -20, -56, 79, -74, -81]
    tree = BTree(5)
    for i in sequence:
        tree.insert(i)
    print(tree.traverse())