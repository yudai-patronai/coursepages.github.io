n, m =  map(int,input().split())
A = []
for i in range(n):
    A.append(['.'] * m)
for i in range(n):
    for j in range(m):
        if (i + j) % 2 != 0:
            A[i][j] = '*'
for row in A:
    print(' '.join(list(map(str, row))))
