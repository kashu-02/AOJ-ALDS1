from functools import reduce
from operator import add, sub, mul

stack = []
last = 0

input = input().split()

for element in input:
    if element == "+":
        res = stack.pop()
        res += stack.pop()
        stack.append(res)
    elif element == "-":
        res = 0
        res -= stack.pop()
        res += stack.pop()
        stack.append(res)
    elif element == "*":
        res = stack.pop()
        res *= stack.pop()
        stack.append(res)
    else:
        stack.append(int(element))

print(stack[0])
