#include <stdio.h>
 #include <stdlib.h>

 int asm4(char* in)
 {
     int val;

     asm (
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "push ebx\n\t"
        "sub esp,0x10\n\t"
        "mov DWORD [ebp-0x10],0x252\n\t"
        "mov DWORD [ebp-0xc],0x0\n\t"
        "jmp a27\n\t"
        "a23:"
        "add DWORD [ebp-0xc],1\n\t"
        "a27:\n\t"
        "mov edx,DWORD [ebp-0xc]\n\t"
        "mov eax,DWORD [ebp+0x8]\n\t"
        "add eax,edx\n\t"
        "movzx eax,BYTE [eax]\n\t"
        "test al,al\n\t"
        "jne a23\n\t"
        "mov DWORD [ebp-0x8],0x1\n\t"
        "jmp a138\n\t"
        "a51:"
        "mov edx,DWORD [ebp-0x8]\n\t"
        "mov eax,DWORD [ebp+0x8]\n\t"
        "add eax,edx	\n\t"
        "movzx eax,BYTE [eax]\n\t"
        "movsx edx,al\n\t"
        "mov eax,DWORD [ebp-0x8]\n\t"
        "lea ecx,[eax-0x1]\n\t"
        "mov eax,DWORD [ebp+0x8]\n\t"
        "add eax,ecx	\n\t"
        "movzx eax,BYTE [eax]\n\t"
        "movsx eax,al\n\t"
        "sub edx,eax\n\t"
        "mov eax,edx\n\t"
        "mov edx,eax\n\t"
        "mov eax,DWORD [ebp-0x10]\n\t"
        "lea ebx,[edx+eax*1]		\n\t"
        "mov eax,DWORD [ebp-0x8]\n\t"
        "lea edx,[eax+0x1]\n\t"
        "mov eax,DWORD [ebp+0x8]\n\t"
        "add eax,edx\n\t"
        "movzx eax,BYTE [eax]\n\t"
        "movsx edx,al\n\t"
        "mov ecx,DWORD [ebp-0x8]\n\t"
        "mov eax,DWORD [ebp+0x8]\n\t"
        "add eax,ecx	\n\t"
        "movzx eax,BYTE [eax]\n\t"
        "movsx eax,al\n\t"
        "sub edx,eax	\n\t"
        "mov eax,edx	\n\t"
        "add eax,ebx	\n\t"
        "mov DWORD [ebp-0x10],eax\n\t"
        "add DWORD [ebp-0x8],0x1\n\t"
        "a138:"
        "mov eax,DWORD [ebp-0xc]\n\t"
        "sub eax,0x1\n\t"
        "cmp DWORD [ebp-0x8],eax\n\t"
        "jl a51\n\t"
        "mov eax,DWORD [ebp-0x10]\n\t"
        "add esp,0x10\n\t"
         "nop\n\t"
         "nop\n\t"
         "nop\n\t"
             :"=r"(val)
             : [pInput] "m"(in)
     );

     return val;
 }

 int main(int argc, char** argv)
 {
     printf("0x%x\n", asm4("picoCTF_376ee"));

     return 0;
 }