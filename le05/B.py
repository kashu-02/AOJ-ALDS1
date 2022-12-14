import sys
inf = sys.maxsize
count = 0

def merge(A, left, mid, right):
    global count
    n1 = mid - left
    n2 = right - mid
    L = [0] * (n1 + 1)
    R = [0] * (n2 + 1)
    for i in range(n1-1):
        L[i] = A[left + i]
    for i in range (n2-1):
        R[i] = A[mid + i]
    L[n1] = inf
    R[n2] = inf
    i = 0
    j = 0
    for k in range(left,right-1):
        count += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

def mergeSort(A, left, right):
  if left+1 < right:
    mid = int((left + right) / 2)
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)


n = int(input())
S = list(map(int, input().split()))

mergeSort(S, 0, n)
print(S)
print(count)