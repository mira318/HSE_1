
#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
int main()
{
    int x, y, z, t;
    char x1, x2, x3, x4;
    setlocale(LC_ALL, "rus");
    printf("Введите коды таблицы ASCII ваших цифр\n");
    scanf("%X %X %X %X", &x, &y, &z, &t);
    x1 = char(x);
    x2 = char(y);
    x3 = char(z);
    x4 = char(t);
    printf("x1 = %c\n", x1);
    printf("x2 = %c\n", x2);
    printf("x3 = %c\n", x3);
    printf("x4 = %c\n", x4);
    if (x1 <= '0' || x1 >= '9' || x2 <= '0' || x2 >= '9' || x3 <= '0' || x3 >= '9' || x4 <= '0' || x4 >= '9')
    {
   	 printf("Введён некорректный символ\n");
   	 return 0;
    }
    _asm
    {
    mov al, x1;
    mov cl, x4;
    mov bl, x3;
    cmp cl, al
    jae net;

    cmp cl, bl;
    jnle net;
    cmp al, 39h
    je good1;
    add al, 1;
    mov x1, al;
    jmp exit;

    good1:
    mov al, 30h;
    mov x1, al;
    jmp exit;
    net:
    cmp bl, 30h
    je bad1;
    sub bl, 1;
    mov x3, bl;
    jmp exit;

    bad1:
    mov x3, bl;
    jmp exit;
    exit:nop
    }
    x = x1;
    y = x2;
    z = x3;
    t = x4;
    printf("Результаты тестирования\n");
    printf("Как символы\n");
    printf("%c %c %c %c\n", x1, x2, x3, x4);
    printf("Как коды ASCII\n");
    printf("%X %X %X %X\n", x, y, z, t);
    return 0;
}

