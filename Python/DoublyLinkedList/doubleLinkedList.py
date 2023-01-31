class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def isEmpty(self):
        if self.head == None:
            return True
        return False

    def insertBeg(self, node):
        newNode = Node(node)
        if self.isEmpty():
            self.tail = newNode
            self.head = newNode
            return
        newNode.next = self.head
        self.head.prev = newNode
        self.head = newNode

    def insertEnd(self, node):
        newNode = Node(node)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
            return
        newNode.prev = self.tail
        self.tail.next = newNode
        self.tail = newNode

    def insertAfter(self, target, node):
        if self.isEmpty():
            print("List is empty")
            return
        if self.tail.data == target:
            return self.insertEnd(node)
        newNode = Node(node)
        aux = self.head
        while aux:
            if aux.data == target:
                newNode.next = aux.next
                aux.next = newNode
                return
            aux = aux.next
        print(f"Node {target} was not found")

    def insertBefore(self, target, node):
        if self.isEmpty():
            print("List is empty")
            return
        if self.head.data == target:
            return self.insertBeg(node)
        newNode = Node(node)
        aux = self.head
        while aux:
            if aux.data == target:
                aux.next = newNode
                newNode.next = aux
                return
            aux = aux.next
        print(f"Node {target} was not found")

    def insertOrder(self, node):
        newNode = Node(node)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
        elif node < self.head.data:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        else:
            aux = self.head
            while aux.next != None and aux.next.data < node:
                aux = aux.next
            if aux.next != None:
                aux.next.prev = newNode
            newNode.next = aux.next
            newNode.prev = aux
            if aux.next == None:
                self.tail = newNode
            aux.next = newNode

    def sortLinkedList(self):
        if self.isEmpty():
            print("List is empty")
            return
        aux = self.head
        while aux:
            current = aux.next
            while current:
                if aux.data > current.data:
                    aux.data, current.data = current.data, aux.data
                current = current.next
            aux = aux.next

    def showList(self):
        if self.isEmpty():
            print("List is empty")
            return
        show = self.head
        while show:
            print(show.data)
            show = show.next

    def searchNode(self, node):
        if self.isEmpty():
            print("List is empty")
            return
        current = self.head
        while current:
            if current.data == node:
                return True
            current = current.next
        return False

    def removeNode(self, node):
        self.sortLinkedList()
        if self.isEmpty() or node < self.head.data:
            print("Item is not on the list")
            return
        if node == self.head.data:
            self.head = self.head.next
            self.head.prev = None
            return
        if node == self.tail.data:
            self.tail = self.tail.prev
            self.tail.next = None
            return
        prev = self.head
        while prev.next != None and prev.next.data < node:
            prev = prev.next
        if prev.next == None or prev.next.data > node:
            print("Item is not on the list")
            return
        prev.next = prev.next.next
        prev.next.prev = prev

    def deleteList(self):
        aux = self.head
        while self.head is not None:
            self.head = self.head.next
            aux = None
            aux = self.head
        self = None
