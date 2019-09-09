#!/usr/bin/python3
#coding=utf-8
import urllib.request
import sys


def Euclid(a,b=26):

    x1 = 1

    x2 = 0

    x3 = a

    y1 = 0

    y2 = 1

    y3 = b

 

    while y3 != 0 :

        q = int(x3/y3)

        t1 = x1-q*y1

        t2 = x2-q*y2

        t3 = x3-q*y3

 

        x1 = y1

        x2 = y2

        x3 = y3

 

        y1 = t1

        y2 = t2

        y3 = t3

 

        if x1<0:

            x1 = x1+b

    return x1

 
if(len(sys.argv)<4):
    print("1:encrption 2:decrption")
    print("input a,b,plaintext(ciphertext)定义域[0,25]，且gcd(a,26)=1")
    sys.exit(0)
a = int(sys.argv[2])

b = int(sys.argv[3])
if(int(sys.argv[1])==1):
    m = sys.argv[4]
else:
    c = sys.argv[4]

 

m1=[]

m2=[]

 
if(int(sys.argv[1])==1):
    for i in range(len(m)):

        m1.append(  chr( (a*(ord(m[i])-97)+b)%26+97)  )

 
else:
    for i in range(len(c)):

        m2.append(  chr((  Euclid(a)*((ord(c[i])-97)-b)  )%26+97) )

 

m3=''.join(m1)

m4=''.join(m2)

 

print(m3)

print(m4)
