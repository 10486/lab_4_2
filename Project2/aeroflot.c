#define _CRT_SECURE_NO_WARNINGS
#include "aeroflot.h"
#include <stdio.h>
#include <string.h>
// Ввод данных в структуру
void input_struct(Aeroflot* a) {
	printf("Введите пункт назначения: ");
	scanf("%s", a->destination);
	printf("Введите тип самолета: ");
	scanf("%s", a->type_of_aircraft);
	printf("Введите номер рейса: ");
	scanf("%d", &(a->number));
}
// Вывод структуры в консоль
void output_struct(const Aeroflot* a) {
	printf("-------------------------------\n");
	printf("Номер рейса: %d\n", a->number);
	printf("Тип самолета: %s\n", a->type_of_aircraft);
}
// Сравнение по номеру рейса
// больше нуля если первый пункт назначения больше
// 0 если равны
// меньше нуля если второй пункт назначения больше
char compare_by_number(const Aeroflot* f, const Aeroflot* s) {
	char res;
	if (f->number > s->number) {
		res = 1;
	}
	else if (f->number == s->number) {
		res = 0;
	}
	else {
		res = -1;
	}
	return res;
}