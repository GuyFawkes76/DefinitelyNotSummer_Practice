//	Программа All_Divisors_Of_Natural_Number
//
//	Текущий файл mystacklib.с содержит тела связанных со стеками функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include <math.h>
#include <stdio.h>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement* element;							//Указатель на новый создаваемый элемент списка.
	element = (stackElement*)malloc(sizeof(stackElement));
	element->value = inData;
	element->next = NULL;
	return element;
}

void findAndPrintDivisors(int number) {
	int divisor;						//Текущее число, проверяемое на делитель.
	double numberSqrt = sqrt(number);
	stackElement* curElement = NULL;	//Указатель на текущий элемент.
	for (divisor = numberSqrt; divisor > 0; divisor--) {	//Проверяем, является ли число делителем.
		if (number % divisor == 0) {
			push(&curElement, divisor);
			printf(" %d", divisor);
		}
	}
	return curElement;
}

int getNumber() {
	int number;
	printf("Введите натуральное число n, для которого требуется найти все делители: ");
	if (!scanf("%d", &number)) {
		printf("Введённая строка не является натуральным числом, повторите попытку.");
		exit(0);
	}
	if (number <= 0) {
		printf("Введённое число не является натуральным, повторите попытку.");
		exit(0);
	}
	return number;
}

int getValue(stackElement* element) {
	if (isEmpty(element))	//Если элемента не существует, то возвращаем 0, потому что 0 - удобно, и он не может быть делителем.
		return 0;
	return element->value;
}

int isEmpty(stackElement * element) {
	return !element;
}

void push(stackElement ** prevElement, int value) {
	stackElement* element;			//Указатель на новый создаваемый элемент списка
	element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement** element) {
	if (isEmpty(*element))	//Если элемента не существует, то возвращаем 0, потому что 0 - удобно, и он не может быть делителем.
		return 0;
	int tempValue;					//Указатель на временно хранящееся значение для его возврата.
	stackElement* temp;				//Указатель на элемент, который нужно удалить.
	temp = *element;
	*element = (*element)->next;
	tempValue = getValue(temp);
	free(temp);
	return tempValue;
}

//void printDivisors(stackElement* firstHOD, stackElement* secondHOD) {
//	stackElement* curElement;				//Указатель на текущий элемент стека (сначала одного, потом второго) делителей.
//	for (curElement = firstHOD; curElement; ) {
//		printf(" %d", pop(&curElement));
//	}
//	for (curElement = secondHOD; curElement; ) {
//		printf(" %d", pop(&curElement));
//	}
//	printf(".");
//}