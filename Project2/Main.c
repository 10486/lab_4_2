#define _CRT_SECURE_NO_WARNINGS
#include "aeroflot.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>
// Для работы полностью закоментировать либо файл Main.c либо Main_list.c (для IDE)
// Для простого компилятора просто компилировать либо файл Main.c либо Main_list.c

void main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	printf("Названия писать слитно или через '_'\n");
	int tmp, counter = 0;
	Aeroflot* arr[15];
	do
	{
		// выделяем память и вводим структуру
		arr[counter] = malloc(sizeof(Aeroflot));
		input_struct(arr[counter]);
		counter++;
		printf("продолжить ввод (1-да, 0-нет)\n");
		scanf("%d", &tmp);
	} while (tmp);
	// сортируем
	// arr - указатель на начало массива
	// counter - кол-во элементов
	// sizeof(aeroflot*) - размер элементов
	// compare_by_number - функция для сравнения
	qsort(arr, counter, sizeof(Aeroflot*), compare_by_number);
	char flag = 0, input[TYPE_OF_AIRCRAFT_NAME];
	printf("введите название пункта назначения: ");
	scanf("%s", input);
	for (size_t i = 0; i < counter; i++)
	{
		// выводим только совпадающие по пункту назначения стуктуры
		if (strcmp(arr[i]->destination, input) == 0) {
			output_struct(arr[i]);
			flag = 1;
		}
	}
	if (!flag) {
		printf("Рейсов с таким пунктом назначения нет\n");
	}
}