n = input()
S = list(map(int, input().split()))
q = input()
T = list(map(int, input().split()))

count = 0
left = 0
right = len(S)

def binarySearch(qurey,left,right):
    while left < right:
        mid = int((left + right) / 2)
        if S[mid] == qurey:
            return True
        elif S[mid] > qurey:
            right = mid
        else:
            left = mid + 1
    return False

for i in range(len(T)):
    if binarySearch(T[i], left, right):
        count += 1

print(count)