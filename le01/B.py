input = input().split()

def getGCD(a, b):
    if b == 0:
        return a
    else:
        return getGCD(b, a % b)

print(getGCD(int(input[0]), int(input[1])))

