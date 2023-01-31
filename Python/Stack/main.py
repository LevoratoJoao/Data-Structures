from stack import Stack

stack = Stack()

print(stack.isEmpty())
stack.push("Joao")
stack.push("Marcelo")
stack.push("Barbara")
stack.push("Claudia")
stack.push("Riqueza")

stack.show()

print(f"Last item in stack: {stack.peek()}")

stack.pop()
stack.pop()

stack.show()

stack.free()