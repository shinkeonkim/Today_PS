n=int(input())
L = []
for i in range(n):
    l = list(map(int,input().split()))
    L.append(l)

S = 0
for i in range(n):
    S += abs(L[i][0]-L[i-1][0])
    S += abs(L[i][1]-L[i-1][1])
print(S)