// lab11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#include <string>
typedef struct Node
{
	Node* left, *right;
	char* word;
	int am;
}Node;

void putstr(char* S)
{
	int i;
	for (i = 0; i < strlen(S); ++i)
	{
		printf("%c", S[i]);
	}
	printf("%\t");
}
Node* addNode(char* word2, Node* tree)
{
	if (!tree)
	{
		tree = (Node*)malloc(sizeof(Node));
		tree->word = (char*)malloc((strlen(word2) + 1) * sizeof(char));
		strcpy(tree->word, word2);
		tree->word[strlen(word2)] = '\0';
		tree->am = 1;
		tree->left = tree->right = NULL;
	}
	else if (strcmp(tree->word, word2) > 0)
	{
		tree->left = addNode(word2, tree->left);
	}
	else
	{
		tree->right = addNode(word2, tree->right);
	}
	return tree;
}

Node* find(Node* tree, char* S)
{
	if (!tree)
	{
		return NULL;
	}
	if (strcmp(S, tree->word) == 0)
	{
		return tree;
	}
	if (strcmp(tree->word, S) > 0)
	{
		if (tree->left)
		{
			return find(tree->left, S);
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		if (tree->right)
		{
			return find(tree->right, S);
		}
		else
		{
			return NULL;
		}
	}
}
void prefix(Node* tree)
{
	if (tree)
	{
		printf("Node:");
		putstr(tree->word);
		printf("%d\n", tree->am);
		printf("go to left\n");
		prefix(tree->left);
		printf("go to right\n");
		prefix(tree->right);
		printf("finished, go up\n");
	}
	else
	{
		printf("empty\n");
	}
}
void infex(Node* tree)
{
	if (tree)
	{
		printf("go to left\n");
		infex(tree->left);
		printf("Node:");
		putstr(tree->word);
		printf("%d\n", tree->am);
		printf("go to right\n");
		infex(tree->right);
		printf("finished, go up\n");
	}
	else
	{
		printf("empty\n");
	}
}
void postfix(Node* tree)
{
	if (tree)
	{
		printf("go to left\n");
		postfix(tree->left);
		printf("go to right\n");
		postfix(tree->right);
		printf("Node:");
		putstr(tree->word);
		printf("%d\n", tree->am);
		printf("finished, go up\n");
	}
	else
	{
		printf("empty\n");
	}
}
void bfs(Node* tree)
{
	Node** Queue = NULL;
	Node* El = NULL;
	int curel = 0, quesize = 1, sledlev = 0;
	if (tree)
	{
		Queue = (Node**)realloc(Queue, quesize);
		Queue[0] = tree;
		while (curel < quesize)
		{
			if (curel == sledlev)
			{
				if (sledlev != 0)
				{
					printf("next level:\n");
				}
				sledlev = -1;
			}
			El = Queue[curel];
			printf("Node:");
			putstr(El->word);
			printf("%d\n", El->am);
			if (El->left)
			{
				Queue = (Node**)realloc(Queue, (quesize + 1) * sizeof(Node*));
				Queue[quesize] = El->left;
				if (sledlev == -1)
				{
					sledlev = quesize;
				}
				quesize++;
			}
			if (El->right)
			{
				Queue = (Node**)realloc(Queue, (quesize + 1) * sizeof(Node*));
				Queue[quesize] = El->right;
				if (sledlev == -1)
				{
					sledlev = quesize;
				}
				quesize++;
			}
			curel++;
		}
		free(Queue);
	}
	else
	{
		printf("empty\n");
	}
}

void dfs(Node* tree)
{
	Node** Stack = NULL;
	Node* El = NULL;
	int curel = 0, size = 1;
	if (tree)
	{
		Stack = (Node**)realloc(Stack, size * sizeof(Node*));
		Stack[0] = tree;
		while (size > 0)
		{
			El = Stack[size - 1];
			printf("Node:");
			putstr(El->word);
			printf("%d\n", El->am);
			Stack = (Node**)realloc(Stack, (size - 1) * sizeof(Node));
			size--;
			if (El->right)
			{
				Stack = (Node**)realloc(Stack, (size + 1) * sizeof(Node));
				Stack[size] = El->right;
				size++;
			}
			if (El->left)
			{
				Stack = (Node**)realloc(Stack, (size + 1) * sizeof(Node));
				Stack[size] = El->left;
				size++;
			}
		}
		free(Stack);
	}
	else
	{
		printf("empty\n");
	}
}
void Delete(Node** tree)
{
	Node** Que = NULL;
	int size = 1, curel = 0;
	Node* Cur = NULL, *El;
	if (tree)
	{
		Que = (Node**)realloc(Que, size * sizeof(Node));
		Que[0] = *tree;
		while (curel < size)
		{
			El = Que[curel];
			if (El->left)
			{
				Que = (Node**)realloc(Que, (size + 1) * sizeof(Node));
				Que[size] = El->left;
				size++;
			}
			if (El->right)
			{
				Que = (Node**)realloc(Que, (size + 1) * sizeof(Node));
				Que[size] = El->right;
				size++;
			}
			free(El->word);
			free(El);
			curel++;
		}
		free(Que);
		*tree = NULL;
	}
	else
	{
		printf("already empty\n");
	}
}
Node* createtree(Node** tree)
{
	FILE* f, *f2;
	Node* place;
	char a = ' ';
	char* currentword = NULL;
	int sztek = 0;
	f = fopen("input.txt", "rt");
	if (!f)
	{
		printf("No input file\n");
		return NULL;
	}
	f2 = fopen("input.txt", "rt");
	fseek(f2, 0, SEEK_END);
	printf("there those words in the file:\n");
	while (ftell(f) < ftell(f2))
	{
		fscanf(f, "%c", &a);
		if (a != EOF)
		{
			if (a == ' ' && sztek != 0)
			{
				currentword = (char*)realloc(currentword, (sztek + 1) * sizeof(char));
				currentword[sztek] = '\0';
				puts(currentword);
				place = find(*tree, currentword);
				if (place)
				{
					(place->am)++;
				}
				else
				{
					*tree = addNode(currentword, *tree);
				}
				sztek = 0;
				currentword = (char*)realloc(currentword, 0);
			}
			else
			{
				if (a != ' ')
				{
					currentword = (char*)realloc(currentword, (sztek + 1) * sizeof(char));
					currentword[sztek] = a;
					sztek++;
				}
			}
		}
	}
	if (sztek != 0)
	{
		currentword = (char*)realloc(currentword, (sztek + 1) * sizeof(char));
		currentword[sztek] = '\0';
		puts(currentword);
		place = find(*tree, currentword);
		if (place)
		{
			place->am++;
		}
		else
		{
			*tree = addNode(currentword, *tree);
		}
		sztek = 0;
		free(currentword);
	}
	return *tree;
	fclose(f);
	fclose(f2);
}
void tack(Node* tree)
{
	Node* place;
	char a = ' ';
	char* searchword = NULL;
	int sztek = 0;
	if (tree)
	{
		fseek(stdin, 0, SEEK_END);
		printf("Enter the word for search\n");
		sztek = 0;
		scanf(" ");
		while (a != '\n')
		{
			scanf("%c", &a);
			if (a != '\n')
			{
				searchword = (char*)realloc(searchword, (sztek + 1) * sizeof(char));
				searchword[sztek] = a;
				sztek++;
			}
			else
			{
				searchword = (char*)realloc(searchword, (sztek + 1) * sizeof(char));
				searchword[sztek] = '\0';
				sztek++;
			}
		}
		place = find(tree, searchword);
		if (!place)
		{
			printf("No this word\n");
		}
		else
		{
			printf("This word was met in the file %d times\n", place->am);
		}
		free(searchword);
	}
	else
	{
		printf("the tree is empty, so answer is no this word anyway\n");
	}
}
int main()
{
	Node* TREE = NULL;
	char a = ' ';
	TREE = createtree(&TREE);
	while (a != '0')
	{
		printf("chose what to do:\nDo the tack is 1\nUse the prefix function to write down the tree is 2\n");
		printf("Use the infex function to write down the tree is 3\nUse the postfix function to write down the tree is 4\n");
		printf("Use the bfs function to write down the tree is 5\nUse the dfs function to write down the tree is 6\n");
		printf("Delete the tree is 7\nStop the program is 0\n");
		scanf(" ");
		scanf("%c", &a);
		switch (a)
		{
			case '1':
			{
				tack(TREE);
				break;

			}
			case '2':
			{
				prefix(TREE);
				break;
			}
			case '3':
			{
				infex(TREE);
				break;
			}
			case '4':
			{
				postfix(TREE);
				break;
			}
			case '5':
			{
				bfs(TREE);
				break;
			}
			case '6':
			{
				dfs(TREE);
				break;
			}	
			case '7':
			{
				Delete(&TREE);
				break;
			}
			case '0':
			{
				break;
			}
			default:
			{
				printf("Incorrcet answer, try again\n");
				break;
			}
		}
	}
	return 0;
}

