//	Программа All_Divisors_Of_Natural_Number
//
//	Текущий файл mystacklib.h содержит декларации связанных со стеками функций и типов данных, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//

#ifndef MYSTACKLIB_H
#define MYSTACKLIB_H
typedef struct stackElement {	//Структура, представляющая собой элемент стека
	int value;					//Значение, хранящееся в элементе стека
	struct stackElement * next;	//Указатель на следующий элемент стека
} stackElement;					//Обычный typedef, чтобы не писать везде struct

//Функция, создающая новый элемент стека. На вход принимает значение, которое помещает в элемент. Возвращает указатель на созданный элемент.
//!!!Не забываем очищать память, в случае чего!!!
stackElement* createElement(int inData);

//Функция, заполняющая первую половину стека делителей - до корня из number
stackElement* fillStack(int number, double numberSqrt);

//Функция, запрашивающая ввод натурального числа в консоль. При введении натурального числа возвращает его.
int getNumber();

//Функция, возвращающая значение элемента.
int getValue(stackElement* element);

//Функция, проверяющая, существует ли элемент списка.
int isEmpty(stackElement* element);

//Функция, добавляющая новый элемент в стек. На вход принимает указатель на указатель на текущий элемент и значение, которое помещает в элемент.
//Вызывает createElement, !!!Не забываем очищать память, вызывая pop!!!
void push(stackElement** prevElement, int value);

//Функция, удаляющая элемент из стека и возвращающая его значение. На вход принимает указатель на указатель на элемент.
int pop(stackElement** element);

//Функция, выводящая делители
void printDivisors(stackElement* firstHOD, stackElement* secondHOD);
#endif	//MYSTACKLIB_H
