class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        if self.head == None:
            return True
        return False

    def insertBeg(self, node):
        newNode = Node(node)
        newNode.next = self.head
        self.head = newNode

    def insertEnd(self, node):
        newNode = Node(node)
        if self.isEmpty():
            self.head = newNode
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = newNode

    def insertAfter(self, target, node):
        if self.isEmpty():
            print("List is empty")
            return
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
        elif node < self.head.data:
            newNode.next = self.head
            self.head = newNode
        else:
            aux = self.head
            while aux.next != None and aux.next.data < node:
                aux = aux.next
            newNode.next = aux.next
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
        if self.isEmpty() or node < self.head.data:
            print("Item is not on the list")
            return
        if node == self.head.data:
            self.head = self.head.next
            return
        prev = self.head
        while prev.next != None and prev.next.data < node:
            prev = prev.next
        if prev.next == None or prev.next.data > node:
            print("Item is not on the list")
            return
        prev.next = prev.next.next

    def deleteList(self):
        aux = self.head
        while self.head is not None:
            self.head = self.head.next
            aux = None
            aux = self.head
        self = None
