#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
void append(List* list, Aeroflot* flight) {
	Node* tmp = calloc(1, sizeof(Node));
	tmp->data = flight;
	// Список пустой
	if (list->head == NULL) {
		list->tail = list->head = tmp;
	}
	else {
		// Элемент меньше первого элемента списка
		if (compare_by_number(flight, list->head->data) == -1) {
			list->head->prev = tmp;
			tmp->next = list->head;
			list->head = tmp;
		}
		else {
			Node* current = list->head->next;
			if (current != NULL) {
				// идем по списку пока не найдем элемент списка меньше данного элемента
				while (compare_by_number(flight, current->data) >= 0) {
					//конец списка
					if (current->next == NULL) {
						list->tail = current->next = tmp;
						tmp->prev = current;
						return;
					}
					current = current->next;
				}
			}
			tmp->next = current->next;
			tmp->next->prev = tmp;
			current->next = tmp;
			tmp->prev = current;
		}
	}
}
void find_in_list(List* list, char* dest) {
	char flag = 0;
	// идем по списку
	for (Node* tmp = list->head; tmp != NULL; tmp = tmp->next)
	{
		// выводим нужные рейсы
		if (!strcmp(tmp->data->destination, dest)) {
			output_struct(tmp->data);
			flag = 1;
		}
	}
	if (!flag) {
		printf("Рейсов с таким пунктом назначения нет\n");
	}
}
