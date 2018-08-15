// lab8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#ifndef THE_STRUCT
#include "struct.h"
#endif
#ifndef Fill
#include "Func.h"
#endif
#include <string.h>
//Функция main(). Узнаёт у пользователя, что нужно сделать с базой и вызывает соответствующую функцию,
//в случае удаления/изменения сначала запускает функцию для поиска элемента, а после передаёт полученный ID в функцию удаления/изменения
//Выводит получившуюся базу в случае 
//заполнения базы/добавления нового студента в базу/изменения данных о студенте/удаления студента/сортировки базы/требования вывести базу. 
//Возвращает 0, если работа была завершена корректно и код ошибки в противном случае.
int main()
{
	int val = -1, i;
	Prep();
	while (val != 0)
	{
		printf("chose what to do:\nCreate a new base is 1\nAdd a student is 2\n");
		printf("Alter data about a student is 3\nDelete a student is 4\n");
		printf("Find a student or students is 5\nSort data in the base is 6\n");
		printf("See all the base is 7\nStop the program is 0\n");
		scanf("%d", &val);
		switch(val)
		{
			case 1:
			{
				Fill_Check();
				Print_base_table();
				break;
				
			}
			case 2:
			{
				Add();
				Print_base_table();
				break;
			}
			case 3:
			{
				long long alter_ID;
				alter_ID = search(1);
				if (alter_ID > 0)
				{
					Alter(alter_ID);
					Print_base_table();
				}
				else
				{
					printf("Incorrect ID, try again\n");
				}
				break;
			}
			case 4:
			{
				long long Del_ID;
				Del_ID = search(1);
				if (Del_ID > 0)
				{
					Delete(Del_ID);
					Print_base_table();
				}
				else
				{
					printf("Incorrect ID, try again\n");
				}
				break;
			}
			case 5:
			{
				search(0);
				break;
			}
			case 6:
			{
				pre_Sort();
				Print_base_table();
				break;
			}
			case 7:
			{
				Print_base_table();
				break;
			}
			case 0:
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
