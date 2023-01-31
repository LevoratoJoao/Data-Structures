from queues import MyQueue

queue = MyQueue()

print(queue.isEmpty())

queue.enqueue("Joao")
queue.enqueue("Marcos")
queue.enqueue("Tereza")
print(f"Queue = {queue.show()}")
print(f"{queue.dequeue()} was removed from the queue")

print(f"Queue size = {queue.size()}")
print(queue.isFull())
print(f"First in queue = {queue.peek()}")
print(f"Queue = {queue.show()}")
queue.free()