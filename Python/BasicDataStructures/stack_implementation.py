class Stack:
    def __init__(self):
        self.stack = []

    def push(self,item):
        self.stack.append(item)

    def pop(self):
        return self.stack.pop() if self.stack else None
    

s = Stack()
s.push(1)
s.push(10) 
s.push(30)
print(s.pop())  # 30
print(s.pop())  # 10