#include "stdafx.h"
#include <malloc.h>
#include <string>
typedef struct Node
{
	char* word;
	struct Node* next;
	struct Node* prev;
} Node;
//Функция вывода списка на экран. Если список пустой, оповещает об этом пользователя, иначе выводит его содержимое от начала.
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
		puts(tmp->word);
		tmp = tmp->next;
	}
}
//Функция добавления элемента в конец списка. Если список был пустым, указатель на начало списка переставляется в добавляемый элемент
void addEl(Node** head, Node** tail, char* word2)
{
	Node* tmp, *newnode;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->word = (char*)malloc((strlen(word2) + 1) * sizeof(char));
	strcpy(newnode->word, word2);
	newnode->word[strlen(word2)] = '\0';
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!(*head))
	{
		(*head) = newnode;
		(*tail) = newnode;
	}
	else
	{
		tmp = (*tail);
		tmp->next = newnode;
		newnode->prev = (*tail);
		*tail = newnode;
	}
}
//Фуекция удаления списка
void deletelist(Node** head)
{
	Node* next, *tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->word);
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}
//Функция удаления записи из списка
void delNode(Node** head, Node** tail, Node** eln)
{
	if ((*eln)->prev)
	{
		(*eln)->prev->next = (*eln)->next;
	}
	if ((*eln)->next)
	{
		(*eln)->next->prev = (*eln)->prev;
	}
	if (!(*eln)->prev)
	{
		(*head) = (*eln)->next;
	}
	if (!(*eln)->next)
	{
		(*tail) = (*eln)->prev;
	}
	(*eln)->prev = NULL;
	(*eln)->next = NULL;
	free((*eln)->word);
	free((*eln));
}
//Функция выполнения задания. Узнаёт у пользователя длину удаляемых слов и удаляет все элементы списка с заданной длиной
void tack(Node** head, Node** tail)
{
	int flag = 1, Len;
	Node* tmp, *nexttmp;
	tmp = *head;
	nexttmp = (*head)->next;
	fseek(stdin, 0, SEEK_END);
	printf("Input the length of word for deleting.\n");
	while (flag)
	{
		scanf("%d", &Len);
		if (Len <= 0)
		{
			printf("Incorrect answer write another length.\n");
		}
		else
		{
			flag = 0;
		}
	}
	while (tmp != NULL)
	{
		if (strlen(tmp->word) == Len)
		{
			delNode(head, tail, &tmp);
		}
		tmp = nexttmp;
		if (tmp)
		{
			nexttmp = tmp->next;
		}
	}
}
//Функция main() считывает строку, заданную пользователем, выводит получившийся список на экран, 
//запускает функцию выполнения задания, выводит результат его выполнения и удаляет список при согласии пользователя  
int main()
{
	int flag = 1, sztek = 0;
	char a;
	char* S = NULL;
	Node* head = NULL, *tail = NULL;
	printf("Enter your string.\n");
	scanf(" ");
	while (flag)
	{
		scanf("%c", &a);
		if (a == '.')
		{
			flag = 0;
		}
		else
		{
			if (a == ' ' && sztek != 0)
			{
				S = (char*)realloc(S, (sztek + 1) * sizeof(char));
				S[sztek] = '\0';
				addEl(&head, &tail, S);
				sztek = 0;
				S = (char*)realloc(S, 0);
			}
			else
			{
				if (a != ' ')
				{
					S = (char*)realloc(S, (sztek + 1) * sizeof(char));
					S[sztek] = a;
					sztek++;
				}
			}
		}
	}
	if (sztek != 0)
	{
		S = (char*)realloc(S, (sztek + 1) * sizeof(char));
		S[sztek] = '\0';
		addEl(&head, &tail, S);
		free(S);
	}
	printf("Your list:\n");
	printlist(head);
	tack(&head, &tail);
	printf("After the tack:\n");
	printlist(head);
	printf("Do you want to delete the list? Write Y or N\n");
	scanf(" %c", &a);
	while (a != 'N')
	{
		if (a == 'Y')
		{
			deletelist(&head);
			break;
		}
		else
		{
			printf("Incorrect symbol, try again.\n");
			scanf(" %c", &a);
		}
	}
	printf("After deleting\n");
	printlist(head);
	return 0;
}