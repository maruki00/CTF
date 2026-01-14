;What does asm2(0x4,0x21) return?
asm2:
	<+0>:	push   ebp
	<+1>:	mov    ebp,esp
	<+3>:	sub    esp,0x10                	  ;				 16
	<+6>:	mov    eax,DWORD PTR [ebp+0xc] 	  ;	eax = 116    ebp+12
	<+9>:	mov    DWORD PTR [ebp-0x4],eax 	  ;	localv1 = 116    ebp-4
	<+12>:	mov    eax,DWORD PTR [ebp+0x8] 	  ;	eax = 4	 ebp+8
	<+15>:	mov    DWORD PTR [ebp-0x8],eax 	  ;	localv2 = 4  	 ebp-8
	<+18>:	jmp    0x509 <asm2+28>         	  ; 
	<+20>:	add    DWORD PTR [ebp-0x4],0x1 	  ; 1
	<+24>:	add    DWORD PTR [ebp-0x8],0x74	  ; 116
	<+28>:	cmp    DWORD PTR [ebp-0x8],0xfb46 ; 
	<+35>:	jle    0x501 <asm2+20>            ;
	<+37>:	mov    eax,DWORD PTR [ebp-0x4]    ;
	<+40>:	leave  
	<+41>:	ret    

