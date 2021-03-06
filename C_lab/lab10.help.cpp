#include "stdafx.h"
#include <malloc.h>
#include <string>
typedef struct Node
{
	char* word;
	struct Node* next;
	struct Node* prev;
} Node;
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
Node* getNode(Node* head, Node* tail, int sz, int number)
{
	Node* tmp;
	int i;
	if (number < sz / 2)
	{
		i = 0;
		tmp = head;
		while (tmp && i < number)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = sz - 1;
		tmp = tail;
		while (tmp && i > number)
		{
			tmp = tmp->prev;
			i--;
		}
	}
	return tmp;
}
void insert(Node* head, Node** tail, int number, int sz, char* S)
{
	Node* eln, *ins;
	eln = getNode(head, *tail, sz, number);
	ins = (Node*)malloc(sizeof(Node));
	ins->word = (char*)malloc((strlen(S) + 1) * sizeof(S));
	strcpy(ins->word, S);
	ins->word[strlen(S)] = '\0';
	ins->next = NULL;
	ins->prev = NULL;
	if (eln->next)
	{
		eln->next->prev = ins;
		ins->next = eln->next;
	}
	eln->next = ins;
	ins->prev = eln;
	if (!eln->next)
	{
		(*tail) = ins;
	}
}
void tack(Node** head, Node** tail, int* listsz)
{
	int flag = 1, index, minlen = -1;
	Node* tmp, *nexttmp;
	char* copyword = NULL;
	tmp = *head;
	nexttmp = (*head)->next;
	fseek(stdin, 0, SEEK_END);
	printf("Input the index for inserting.\n");
	while (flag)
	{
		scanf("%d", &index);
		if (index > (*listsz) || index <= 0)
		{
			printf("Incorrect index write another.\n");
		}
		else
		{
			flag = 0;
		}
	}
	while (tmp != NULL)
	{
		if (strlen(tmp->word) < minlen || minlen == -1)
		{
			minlen = strlen(tmp->word);
			copyword = (char*)malloc((minlen + 1) * sizeof(char));
			strcpy(copyword, tmp->word);
			copyword[minlen] = '\0';
		}
		tmp = nexttmp;
		if (tmp)
		{
			nexttmp = tmp->next;
		}
	}
	index--;
	insert(*head, tail, index, *listsz, copyword);
	listsz++;
}
int main()
{
	int flag = 1, sztek = 0, listsz = 0;
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
				listsz++;
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
		listsz++;
		free(S);
	}
	printf("Your list:\n");
	printlist(head);
	tack(&head, &tail, &listsz);
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