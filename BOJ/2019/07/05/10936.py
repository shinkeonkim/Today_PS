import base64
a=input()
print(str(base64.b32encode(a.encode('utf-8')))[2:-1])