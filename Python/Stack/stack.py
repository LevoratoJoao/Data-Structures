class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def peek(self):
        return self.items[len(self.items) - 1]

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.isEmpty():
            return print("Stack is empty")
        self.items.pop()

    def show(self):
        if self.isEmpty():
            return print("Stack is empty")
        print(f"Stack items: {self.items}")

    def free(self):
        while self.items != []:
            self.pop()
        return print("Stack is empty")