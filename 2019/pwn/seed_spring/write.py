from pwn import *
from time import sleep
found = 0
from random import randint
lvl = 1
#io = ELF('./foo')
#proc = io.process()
while not found:
	sleep(0.01)
	io = ELF('./foo')
	proc = io.process()
	res = proc.read()
	x = randint(1,30)&0xf
	proc.sendline(f'{x}'.encode())
	res = proc.read()
	if b"WRONG! Sorry, better luck next time!" not in res:
		lvl+=1
		print(res.decode())
		while(lvl<31):
			proc.sendline(f'{x}'.encode())
			res = proc.read()
			print(res.decode())
			if b"WRONG! Sorry, better luck next time!" in res:
				proc.close()
				break
			lvl+=1
	else:
		proc.close()
