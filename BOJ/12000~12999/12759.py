def f(ar):
    for i in range(3):
        if ar[i][0] == ar[i][1] == ar[i][2] and ar[i][0] > 0:
            return True
    for i in range(3):
        if ar[0][i] == ar[1][i]  == ar[2][i] and ar[0][i] > 0:
            return True
    for i in range(1,3):
        if ar[0][0] != ar[i][i]:
            break
    else: 
        if ar[0][0] > 0:
            return True
    
    for i in range(1,3):
        if ar[0][2] != ar[i][2-i]:
            break
    else:
        if ar[0][2] > 0:
            return True
    
    return False

L = [[0]*3 for i in range(3)]
ll = []
player = int(input()) -1
for i in range(9):
    ll.append(list(map(int,input().split())))
for i in range(9):
    a,b = ll[i]
    L[a-1][b-1] = player + 1
    if f(L):
        print(player + 1)
        break
    player = 1 - player
else:
    print(0)