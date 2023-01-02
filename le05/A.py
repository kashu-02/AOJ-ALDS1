import pypyjit
pypyjit.set_param('max_unroll_recursion=-1')

n = int(input())
A = list(map(int, input().split()))
q = int(input())
m = list(map(int, input().split()))

def solve(i, mm):
    if mm == 0:
        return True
    if i >= n:
        return False
    res = solve(i + 1, mm) or solve(i + 1, mm - A[i])
    return res

for i in range(q):
    if solve(0, m[i]):
        print("yes")
    else:
        print("no")