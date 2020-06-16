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

stackElement* createElement(int inData);
int getValue(stackElement* element);
void push(stackElement** prevElement, int value);
int pop(stackElement** element);

#endif	//MYSTACKLIB_H