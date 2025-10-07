from sys import *
from random import *

N = 100
if len(argv) > 1:
    N = int(argv[1])
M = 100
if len(argv) > 1:
    M = int(argv[2])
print(N, M)
for i in range(N):
    for j in range(M):
        print(randint(0,9), end = ' ')
    print()

