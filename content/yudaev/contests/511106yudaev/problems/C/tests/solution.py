n, m = map(int, input().split())
A = []
for i in range(n):
    A.append(list(map(int, input().split())))
M = A[0][0] - 1
for i in range(n):
    for j in range(m):
        if A[i][j] > M:
            M = A[i][j]
            row = i
            col = j
print(row, col)

