from queue import Queue

# Enqueue: Add an element to the end of the queue
# Dequeue: Remove an element from the front of the queue
# IsEmpty: Check if the queue is empty
# Peek: Get the value of the front of the queue without removing it

class MyQueue:
    def __init__(self):
        self.items = Queue(maxsize=0) # 0 = infinite queue. maxsize=Number of items allowed in the queue.

    def isEmpty(self):
        return self.items.empty()

    def isFull(self):
        return self.items.full()

    def size(self):
        return self.items.qsize()

    def peek(self):
        return self.items.queue[0]

    def show(self):
        return (list(self.items.queue))

    def enqueue(self, item):
        self.items.put(item)

    def dequeue(self):
        if self.isEmpty():
            return print("Queue is empty\n")
        return self.items.get()

    def free(self):
        while not self.isEmpty():
            self.dequeue()
        return print("Queue is empty")