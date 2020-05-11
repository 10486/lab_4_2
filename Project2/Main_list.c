#define _CRT_SECURE_NO_WARNINGS
#include "aeroflot.h"
#include "List.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <Windows.h>
void main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Названия писать слитно или через '_'\n");
	int counter = 0, tmp;
	List* list = calloc(1, sizeof(List));
	Aeroflot* t;
	do
	{
		// Выделяем память и вводим структуру
		t = malloc(sizeof(Aeroflot));
		input_struct(t);
		// Добавляем в список
		append(list, t);
		counter++;
		printf("Продолжить ввод (1-да, 0-нет)\n");
		scanf("%d", &tmp);
	} while (tmp);
	char flag = 0, input[TYPE_OF_AIRCRAFT_NAME];
	printf("Введите название пункта назначения: ");
	scanf("%s", input);
	find_in_list(list, input);
}