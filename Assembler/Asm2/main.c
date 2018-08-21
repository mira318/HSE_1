#include <stdio.h>
#include <locale.h>
int main()
{
	int var;
	char x, z;
	short y, v, vc;
	setlocale(LC_ALL, "rus");
	scanf("%d", &var);
	if (var == 1)
	{
		x = -0x3;
		y = 0x3;
		z = -0x3;
		printf("Входные данные:\n");
		printf("x = %X\n", x);

		printf("y = %X\n", y);

		printf("z = %X\n", z);
	}
	else
	{
		x = 0x7e;
		y = 0x4000;
		z = -0x70;
		printf("x = %X\n", &x);

		printf("y = %X\n", &y);

		printf("z = %X\n", &z);
	}
	_asm
	{
		mov al, x;
		cbw;
		add ax, 2;
		mov v, ax;
		imul y; //результат в Dx:Ax
		mov bx, ax;
		mov cx, dx; //результат в Cx:Bx
		mov ax, 1;
		cwd;
		sub bx, ax; //младшие разряды
		sbb cx, dx; //старшие разряды
		//числитель Cx:Bx
		mov al, z;
		cbw;//результат в Ax
		add ax, 2;
		xchg cx, dx;
		xchg ax, bx;
		//Числитель Dx:Ax
		//Знаменатель Bx
		idiv bx;
		xchg cx, ax;
		//Результат в Cx
		mov al, -2;
		cbw;
		sub ax, cx;
		//результат в Ax
		mov v, ax;
	}
	vc = ((x + 2)*y - 1)/(z + 2);
	printf("Результаты работы:\n");
	printf("v = %x в шестнадцатеричной системе счисления\n", &v);
	printf("v = %d в десятичной системе счисления\n", &v);

	printf("vс = %x в шестнадцатеричной системе счисления\n", &vс);
	printf("vс = %d в десятичной системе счисления\n", &vс);
	return 0;
}
