import base64
print(str(base64.b16decode(input().encode('utf-8')))[2:-1])