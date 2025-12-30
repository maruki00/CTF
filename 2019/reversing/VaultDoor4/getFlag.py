#!/usr/bin/env python

from email import charset
from unittest.result import failfast


decimal= [106 , 85  , 53  , 116 , 95  , 52  , 95  , 98]
hexes  = [0x55, 0x6e, 0x43, 0x68, 0x5f, 0x30, 0x66, 0x5f]
octals = [0o142, 0o131, 0o164, 0o63 , 0o163, 0o137, 0o143, 0o61]
chares = ['9' , '4' , 'f' , '7' , '4' , '5' , '8' , 'e' ]

flag = ""
flag += "".join(list(map(lambda x : chr(x),decimal)))
flag += "".join(list(map(lambda x : chr(x),hexes)))
flag += "".join(list(map(lambda x : chr(x),octals)))
flag += "".join(chares)


print(flag)
