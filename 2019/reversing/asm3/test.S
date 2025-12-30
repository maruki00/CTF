asm3(0xd2c26416,0xe6cf51f0,0xe54409d5) 
;
; 0xe=14    0xf=15  0x12=18 0x10=16 0x9=9
;
;
;	0xd2c26416, 0xe6cf51f0, 0xe54409d5
;   3535954966, 3872346608, 3846441429                                                      00 00 00 00
;                                                                                           e5 44 09 d5
;                                                                                           e6 cf 51 f0
;                                                                                           d2 c2 64 16
;																							00 00 00 00 
;																					ebp ->  00 00 00 00  
;
;                                                                                   eax ->  00 00 f0 51
;                                                                                                 ah al
;																								  [ ax ]	
;																						
;
asm3:
	<+0>:	push   ebp                     
	<+1>:	mov    ebp,esp
	<+3>:	xor    eax,eax                 
	<+5>:	mov    ah,BYTE PTR [ebp+0x9]   
	<+8>:	shl    ax,0x10                 
	<+12>:	sub    al,BYTE PTR [ebp+0xe]    
 	<+15>:	add    ah,BYTE PTR [ebp+0xf]   
	<+18>:	xor    ax,WORD PTR [ebp+0x12]  
	<+22>:	nop
	<+23>:	pop    ebp
	<+24>:	ret    

