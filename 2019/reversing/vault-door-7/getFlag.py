#!/usr/bin/env python


values = [1096770097
          ,1952395366
          ,1600270708
          ,1601398833
          ,1716808014
          ,1734291511
          ,960049251
          ,1681089078]

print("picoCTF{",end="")
for var in values:
    tmp = bin(var)[2:]
    if len(tmp)%4!=32:
        tmp = "0"*(32-len(tmp))+tmp
    for i in range(4):
        #print(chr(int('0b%s'%(tmp[i,(i+1)*8],2))),end="")
        print(chr(int("0b"+tmp[i*8:(i+1)*8],2)),end="")

print("}")