#include <stdio.h>

int getFlag(int x,int y){
    int v1,v2,v3,v4;
    v1 = y;
    v2 = x;
    while(v2<=0xfb46){
        v1 += 0x1;
        v2 += 0x74;
    }
    return v1;
}
int main(){
    int val1 = 0x4;
    int val2 = 0x21;
    printf("0x%x\n",getFlag(val1,val2));
    return 0;
}