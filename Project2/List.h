#pragma once
#include "aeroflot.h"
// описание списка
typedef struct list
{
	struct node* head;
	struct node* tail;
}List;
// элемент списка со ссылками на следующий и предыдущий элементы
typedef struct node
{
	struct node* next;
	struct node* prev;
	Aeroflot* data;
}Node;
void append(List* list, Aeroflot* flight);
void find_in_list(List* list, char* number);