
#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
int main()
{
    char A[16], B[15];
    char C[30];
    int i, val;
    char am;
    setlocale(LC_ALL, "rus");
    setlocale(LC_NUMERIC, "eng");
    printf("Введите элементы массива А - целые числа от -127 до 128\n");
    for (i = 0; i < 16; ++i)
    {
   	 scanf_s("%d", &val);
   	 //printf("val = %d\n", val);
   	 A[i] = char(val);
   	 printf("A[%d] = %d\n", i, (int)A[i]);
    }
    _asm
    {
   	 lea eSI, A;
   	 lea eBx, B;
   	 lea eDI, C;
   	 mov eCx, 15;
   	 mov DL, 0;
    START:
   	 mov Al, [eSI + 0];
   	 mov Ah, [eSI + 1];
   	 sub Al, Ah;
   	 mov [eBx + 0], Al;
   	 cmp [eBx + 0], -2
   		 jnge out1;
   	 mov [eDI], eBx;
   	 inc DL;
   	 inc eDI;
   	 jmp out1;

    out1:
   	 //sub Ch, 1;
   	 //cmp Ch, 0
   		 //jle FINISH;
   	 inc eBx;
   	 inc eSI;
   	 Loop START;
    FINISH:
   	 mov am, DL;
   	 //mov check, Ch;
    }
    for (i = 0; i < 15; ++i)
    {
   	 printf("B[%d] = %d\n", i, (int)B[i]);
    }
    printf("Количество элементов >= -2 в массиве В = %d\n", (int)am);
    //printf("check = %d\n", (int)check);
    printf("Адреса этих элементов:\n");
    for (i = 0; i < (int)am; ++i)
    {
   	 printf("C[%d] = %X\n", i, C[i]);
   	 //printf("am = %d\n", (int)am);
    }
    //printf("done\n");
    return 0;
}


