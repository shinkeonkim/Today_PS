n = int(input())
if n ==1:
    print(1)
elif n==2:
    print(1)
else:
    a = 1
    b = 1
    for i in range(3,n+1):
        c = a+b
        a,b = b,c
    print(b)