from doubleLinkedList import DoubleLinkedList

linkedList = DoubleLinkedList()

linkedList.showList()

linkedList.insertBeg(2)
linkedList.insertBeg(4)
linkedList.showList()

linkedList.insertEnd(5)

linkedList.insertBefore(4, 3)
linkedList.insertAfter(5, 6)

linkedList.insertOrder(1)

linkedList.sortLinkedList()

linkedList.showList()

print(linkedList.searchNode(5))

print("removendo...")
linkedList.removeNode(1)
linkedList.showList()

print("removendo...")
linkedList.removeNode(4)
linkedList.showList()

print("removendo...")
linkedList.removeNode(2)
linkedList.showList()

print("removendo...")
linkedList.removeNode(8)
linkedList.showList()

print("removendo...")
linkedList.removeNode(6)
linkedList.showList()

linkedList.deleteList()

linkedList.showList()