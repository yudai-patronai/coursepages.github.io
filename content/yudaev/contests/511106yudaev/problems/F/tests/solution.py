(n,m)=list(map(int,input().split()))
A=[0]*n
for s in range(n):
	A[s]=input().split()
(n,m)=list(map(int,input().split()))
for s in A:
	(s[n],s[m])=(s[m],s[n])
	print(" ".join(s))
