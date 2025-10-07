(n,m)=list(map(int,input().split()))
A=[0]*n
for i in range(n):
	A[i]=input().split()
for i in range(m):
	for j in range(n):
		print(A[j][i],end=" ")
	print()
