#!/usr/bin/env python3


from select import select


arch = input("Enter arch (x64,x86):")
inpt = input("Enter you data:")
data = ""

if arch not in ("x64","x86","64","86","32") or inpt == "":
    print("Invalide data!")
    exit(-1)
if arch in("x86","86"):
    for index,char in enumerate(inpt):
        if index%4 == 0:
            data += "|"+hex(ord(char))
        else:
            data += hex(ord(char))[2:]
if arch in("x64","64"):
    for index,char in enumerate(inpt):
        if index%8 == 0:
            data += "|"+hex(ord(char))
        else:
            data += hex(ord(char))[2:]



[print(i) for i in data.split("|")]