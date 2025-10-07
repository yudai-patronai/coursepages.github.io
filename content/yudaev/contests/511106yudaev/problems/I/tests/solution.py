n=int(input())
A=[0]*n
for i in range(n):
	A[i]=input().split()
for i in range(0,n):
	for j in range(n-1,-1,-1):
		print(A[j][i],end=" ")
	print()
