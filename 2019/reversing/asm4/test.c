#include <stdio.h>

void test(char * var){
    char x[0x10];
    printf("%c\n",var[0]);
    printf("%c\n",var[12]);
}

int main(){
    test("picoCTF_724a2");
    return 0;
}