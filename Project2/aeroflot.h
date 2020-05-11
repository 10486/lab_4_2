#pragma once
#define DESTNATION_NAME_LENGTH 30 //длинна названия пункта назначения
#define TYPE_OF_AIRCRAFT_NAME 20 // длинна названия типа самолета
// Определение структуры
typedef struct aeroflot
{
	char destination[DESTNATION_NAME_LENGTH];
	int number;
	char type_of_aircraft[TYPE_OF_AIRCRAFT_NAME];
}Aeroflot;
// Объявление функций связанныху со структурой
void input_struct(Aeroflot* a);
void output_struct(Aeroflot* a);
char compare_by_number(const Aeroflot* f, const Aeroflot* s);