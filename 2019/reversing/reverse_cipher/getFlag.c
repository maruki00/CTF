#include <stdio.h>
#include <stdlib.h>
int main(){
    char buffer[23];
    char flag[23];
    char tmp;
    char swap='}';
    int i,j;
    FILE *_FLAG,*_REVT;
    _FLAG=fopen("flag.txt","r");
    _REVT=fopen("rev_this","w+");    
    if(_FLAG==NULL) exit(-1);
    if(_REVT==NULL) exit(-1);
    int res = fread(buffer,0x18uLL,1uLL,_FLAG);
    if(res <= 0) exit(0);
    for(i=0;i<8;i++){
        tmp = buffer[i];
        flag[i] = buffer[i];
        fputc(tmp, _REVT);
    }
    for(j=8;j<23;++j){
        tmp = buffer[j];
        if ( (j & 1) != 0 )
        tmp += 2;
        else
        tmp -= 5;
        flag[i] = tmp;
        fputc(tmp, _REVT);
    }
    tmp = swap;
    flag[j] = swap;
    fputc(swap, _REVT);
    fclose(_REVT);
    printf("%s\n",flag);
    return fclose(_FLAG);

}