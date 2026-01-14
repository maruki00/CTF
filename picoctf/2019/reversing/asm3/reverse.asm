global _start
_start:
    push 0xe54409d5
    push 0xe6cf51f0
    push 0xd2c26416
    call add

add:
	push   ebp                     
	mov    ebp,esp
	xor    eax,eax                 
	mov    ah,BYTE  [ebp+0x9]   
	shl    ax,0x10                 
	sub    al,BYTE  [ebp+0xe]    
 	add    ah,BYTE  [ebp+0xf]   
	xor    ax,WORD  [ebp+0x12]  
	nop
	pop    ebp
	ret    

