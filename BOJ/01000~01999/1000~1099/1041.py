n=int(input())
L=list(map(int,input().split()))
S = 0
e = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,5],[1,3],[2,4],[2,5],[3,4],[3,5],[4,5]]
v = [[0,1,2],[0,1,3],[0,2,4],[0,3,4],[5,1,2],[5,1,3],[5,2,4],[5,3,4]]

if n == 1:
    print(sum(L)-max(L))
else:
    S += min(L)*(n-2)*(n-2)*5
    
    M =987654321
    for i in e:
        if M> L[i[0]]+L[i[1]]:
            M = L[i[0]]+L[i[1]]
    S += M*((n-2)*8+4)
    
    M =987654321
    for i in v:
        if M> L[i[0]]+L[i[1]]+L[i[2]]:
            M = L[i[0]]+L[i[1]]+L[i[2]]
    S += M*4

    S += (n-2)*4*min(L)

    print(S)