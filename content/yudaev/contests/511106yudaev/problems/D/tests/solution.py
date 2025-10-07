n = int(input())
A = []
for i in range(n):
    A.append(['.'] * n)
for i in range(n):
    A[n//2][i] = '*'
    A[i][n//2] = '*'
    A[i][i] = '*'
    A[i][-1-i] = '*'
for row in A:
    print(' '.join(list(map(str, row))))

