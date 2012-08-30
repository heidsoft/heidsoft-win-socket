/* 
 * File:   main.c
 * Author: liubin
 * 作用：该程序用来确定主机的字节序
 * Created on 2012年8月30日, 下午9:38
 */

#include "unp1/lib/unp.h"

int main(int argc, char** argv) {
    
    union{
        short s;
        char  c[sizeof(short)];
    }un;
    
    un.s=0x0102;
    
    printf("%s: ",CPU_VENDOR_OS);
    if(sizeof(short)==2){
        if(un.c[0]==1&&un.c[1]==2)
            printf("big-endian\n");
        else if(un.c[0]==2&&un.c[1]==1)
            printf("little-endian");
        else
            printf("unknown\n");
        
    }else{
        printf("sizeof(short)=%d\n",sizeof(short));
    }
      
    return (EXIT_SUCCESS);
}

