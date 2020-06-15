//	Программа All_Divisors_Of_Natural_Number
//
//	Текущий файл mystacklib.h содержит декларации связанных со стеками функций и типов данных, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//

#ifndef MYSTACKLIB_H
#define MYSTACKLIB_H
typedef struct stackElement {
	int value;
	struct stackElement * next;
} stackElement;
void pop(stackElement element); 
void push();

#endif	//MYSTACKLIB_H