#include "stdafx.h"
#include <malloc.h>
typedef struct Node
{
	int koeff;
	int pow;
	struct Node* next;
} Node;
void printlist(Node* head)
{
	Node* mytmp;
	if (!head)
	{
		printf("This list is empty\n");
	}
	else
	{
		mytmp = head;
		while (mytmp)
		{
			if (mytmp->koeff > 0 && mytmp != head)
			{
				printf("+%dX^%d", (mytmp->koeff), (mytmp->pow));
			}
			else
			{
				printf("%dX^%d", (mytmp->koeff), (mytmp->pow));
			}
			mytmp = mytmp->next;
		}
		printf("\n");
	}
}
void addEl(Node** head2, int kof2, int pow2)
{
	Node* mytmp, *mynewnode;

	mynewnode = (Node*)malloc(sizeof(Node));
	mynewnode->koeff = kof2;
	mynewnode->pow = pow2;

	mynewnode->next = NULL;
	if (!(*head2))
	{
		(*head2) = mynewnode;
	}
	else
	{
		mytmp = (*head2);
		while (mytmp->next)
		{
			mytmp = mytmp->next;
		}
		mytmp->next = mynewnode;
	}
}

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

void tack(Node* heada, Node* headb, Node** headc2)
{
	Node* my_tmp;
	my_tmp = heada;
	while (my_tmp)
	{
		if ((my_tmp->pow) % 2 == 1)
		{
			addEl(headc2, (my_tmp->koeff), (my_tmp->koeff));
		}
		my_tmp = my_tmp->next;
	}
	my_tmp = headb;
	while (my_tmp)
	{
		if ((my_tmp->pow) % 2 == 0)
		{
			addEl(headc2, (my_tmp->koeff), (my_tmp->pow));
		}
		my_tmp = my_tmp->next;
	}
}
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

int main()
{
	int am1, am2, i, flag = 1, curkof, curpow;
	char a;
	Node* head1 = NULL, *head2 = NULL, *head3 = NULL;
	printf("Enter amount of elements in your first polynom.\n");
	scanf("%d", &am1);
	for (i = 0; i < am1; ++i)
	{
		while (flag)
		{
			printf("element %d\n", i + 1);
			printf("kof:");
			scanf("%d", &curkof);
			if (curkof == 0)
			{
				printf("Incorrect coefficient, try again\n");
			}
			else
			{
				printf("pow:");
				scanf("%d", &curpow);
				//printf("curpow = %f\n", curpow);
				if (check(head1, curpow))
				{
					printf("You have already used that pow, try again\n");
				}
				else
				{
					flag = 0;
					addEl(&head1, curkof, curpow);
				}
			}
		}
		flag = 1;
	}
	printf("Enter amount of elements in your second polynom.\n");
	scanf("%d", &am2);
	for (i = 0; i < am2; ++i)
	{

		while (flag)
		{
			printf("element %d\n", i + 1);
			printf("kof:");
			scanf("%d", &curkof);
			if (curkof == 0)
			{
				printf("Incorrect coefficient, try again\n");
			}
			else
			{
				printf("pow:");
				scanf("%d", &curpow);
				if (check(head2, curpow))
				{
					printf("You have already used that pow, try again\n");
				}
				else
				{
					flag = 0;
					addEl(&head2, curkof, curpow);
				}
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
	printf("after the tack:\n");
	printf("Polinom1\n");
	printlist(head1);
	printf("Polinom2\n");
	printlist(head2);
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

