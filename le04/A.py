n = input()
S = list(map(int, input().split()))
q = input()
T = list(map(int, input().split()))

count = 0

def search(qurey):
    for i in range(len(S)):
        if qurey == S[i]:
            return True
    return False

for i in range(len(T)):
    if search(T[i]):
        count += 1

print(count)