// lab_9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
typedef struct Node
{
	int kof;
	int pow;
	struct Node* next;
} Node;
//Функция вывода списка на экран. Проверяет, что список не пуст и выводит либо сообщение о том, что список пуст, либо сам список на экран.
void printlist(Node* head)
{
	Node* tmp;
	if (!head)
	{
		printf("This list is empty\n");
	}
	tmp = head;
	while (tmp)
	{
		if (tmp->kof > 0 && tmp != head)
		{
			printf("+%dX^%d", (tmp->kof), (tmp->pow));
		}
		else
		{
			printf("%dX^%d", (tmp->kof), (tmp->pow));
		}
		tmp = tmp->next;
	}
	printf("\n");
}
//Функция добавления элемента в список
void addEl(Node** head, int kof2, int pow2)
{
	Node* tmp, *newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->kof = kof2;
	newnode->pow = pow2;
	newnode->next = NULL;
	if (!(*head))
	{
		(*head) = newnode;
	}
	else
	{
		tmp = (*head);
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newnode;
	}
}
//Функция проверки, встречалась ли заданная степеь в списке ранее.
int check(Node*head, int pow2)
{
	while (head)
	{
		if (head->pow == pow2)
		{
			return 1;
		}
		head = head->next;
	}
	return 0;
}
//Функция удаления списка.
void deletelist(Node** head)
{
	Node* next, *tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}
//Функция выполнения задания. Находит максимальную степень среди степеней элементов многочлена 2,
//добавляет в многочлен 3 все элементы многочлена 1, у которых степень больше, чем максимальная степень в многочлене 2.
//Если многослен 2 пуст, записывает в многослен 3 все элементы многочлена 1
void tack(Node* heada, Node* headb, Node** headc)
{
	Node* tmp = NULL;
	int maxpow2 = 0;
	if (headb)
	{
		maxpow2 = (headb->pow);
		tmp = headb;
		while (tmp->next)
		{
			tmp = tmp->next;
			if (maxpow2 < (tmp->pow))
			{
				maxpow2 = (tmp->pow);
			}
		}
		tmp = heada;
		while (tmp)
		{
			if (tmp->pow > maxpow2)
			{
				addEl(headc, (tmp->kof), (tmp->pow));
			}
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = heada;
		while (tmp)
		{
			addEl(headc, (tmp->kof), (tmp->pow));
			tmp = tmp->next;
		}
	}
}
//Функция main() считывает элементы многочленов 1 и 2, проверяет, что введены неодинаковые степени и коэффициенты не равны 0,
//выводит получившиеся многочлены 1 и 2 на экран, запускает функцию выполнения задания tack, выводит результат её работы,
//удаляет все многочлены с разрешения пользователя, возвращает 0 в случае корректного завершения работы, иначе возвращает код возникшей ошибки.
int main()
{
	int am1, am2, i, flag = 1, curkof, curpow;
	Node* head1 = NULL, *head2 = NULL, *head3 = NULL;
	char a;
	printf("Enter amount of elements in the first polynom.\n");
	scanf("%d", &am1);
	for (i = 0; i < am1; ++i)
	{
		printf("element %d\n", i + 1);
		while (flag)
		{
			printf("kof:");
			scanf("%d", &curkof);
			printf("pow:");
			scanf("%d", &curpow);
			//printf("curpow = %f\n", curpow);
			if (check(head1, curpow))
			{
				printf("Incorrect pow, try again\n");
			}
			else
			{
				flag = 0;
				addEl(&head1, curkof, curpow);
			}
		}
		flag = 1;
	}
	printf("Enter amount of elements in the second polynom.\n");
	scanf("%d", &am2);
	for (i = 0; i < am2; ++i)
	{
		printf("element %d\n", i + 1);
		while (flag)
		{
			printf("kof:");
			scanf("%d", &curkof);
			printf("pow:");
			scanf("%d", &curpow);
			if (check(head2, curpow))
			{
				printf("Incorrect pow, try again\n");
			}
			else
			{
				flag = 0;
				addEl(&head2, curkof, curpow);
			}
		}
		flag = 1;
	}
	printf("Polinom1\n");
	printlist(head1);
	printf("Polinom2\n");
	printlist(head2);
	tack(head1, head2, &head3);
	printf("Polinom3\n");
	printlist(head3);
	while (1)
	{
		printf("Do you want to delete all polinoms? Write Y or N\n");
		scanf(" ");
		scanf("%c", &a);
		if (a != 'N')
		{
			if (a == 'Y')
			{
				deletelist(&head1);
				deletelist(&head2);
				deletelist(&head3);
				break;
			}
			else
			{
				printf("Incorrect letter, try again\n");
			}
		}
		else
		{
			break;
		}
	}
	printf("after the deleting:\n");
	printf("Polinom1\n");
	printlist(head1);
	printf("Polinom2\n");
	printlist(head2);
	printf("Polinom3\n");
	printlist(head3);
	return 0;
}

