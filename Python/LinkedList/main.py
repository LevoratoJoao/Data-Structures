from linkedList import LinkedList

linkedList = LinkedList()

linkedList.showList()
linkedList.insertBeg(2)
linkedList.insertBeg(4)
linkedList.showList()
linkedList.insertEnd(5)
linkedList.insertBefore(4, 3)
linkedList.insertAfter(5, 6)
linkedList.insertOrder(1)
linkedList.sortLinkedList()

print("List now:")
linkedList.showList()
print(linkedList.searchNode(5))

print("removendo...\n")
linkedList.removeNode(4)
linkedList.showList()

print("removendo...\n")
linkedList.removeNode(2)
linkedList.showList()

print("removendo...\n")
linkedList.removeNode(6)
linkedList.showList()

print("removendo...\n")
linkedList.removeNode(2)
linkedList.showList()

linkedList.deleteList()

linkedList.showList()