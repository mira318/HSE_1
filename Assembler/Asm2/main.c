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
		printf("������� ������:\n");
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
		imul y; //��������� � Dx:Ax
		mov bx, ax;
		mov cx, dx; //��������� � Cx:Bx
		mov ax, 1;
		cwd;
		sub bx, ax; //������� �������
		sbb cx, dx; //������� �������
		//��������� Cx:Bx
		mov al, z;
		cbw;//��������� � Ax
		add ax, 2;
		xchg cx, dx;
		xchg ax, bx;
		//��������� Dx:Ax
		//����������� Bx
		idiv bx;
		xchg cx, ax;
		//��������� � Cx
		mov al, -2;
		cbw;
		sub ax, cx;
		//��������� � Ax
		mov v, ax;
	}
	vc = ((x + 2)*y - 1)/(z + 2);
	printf("���������� ������:\n");
	printf("v = %x � ����������������� ������� ���������\n", &v);
	printf("v = %d � ���������� ������� ���������\n", &v);

	printf("v� = %x � ����������������� ������� ���������\n", &v�);
	printf("v� = %d � ���������� ������� ���������\n", &v�);
	return 0;
}
