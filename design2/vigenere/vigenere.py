#!/usr/bin/python
#key='relations'
#plaintext='tomorrowiwillhaveagood'

import sys

if(len(sys.argv)<4):
    print('1:encrption/2:decrption keyword plaintext/ciphertext')
    sys.exit(0)
if(int(sys.argv[1])==1):
    key=sys.argv[2]
    plaintext=sys.argv[3]
    ascii='abcdefghijklmnopqrstuvwxyz'
    keylen=len(key)
    ptlen=len(plaintext)
    ciphertext =''
    i =0
    while i < ptlen:
        j = i % keylen
        k = ascii.index(key[j])
        m = ascii.index(plaintext[i])
        ciphertext += ascii[(m+k)%26]
        i +=1

    print(ciphertext)


#维吉尼亚加密算法 解密
else:
    key=sys.argv[2]
    ciphertext=sys.argv[3]
    ascii='abcdefghijklmnopqrstuvwxyz'
    keylen=len(key)
    ctlen=len(ciphertext)
    plaintext =''
    i =0
    while i < ctlen:
        j = i % keylen
        k = ascii.index(key[j])
        m = ascii.index(ciphertext[i])
        if m < k:
            m +=26
        plaintext += ascii[m-k] 
        i +=1
    print(plaintext)
