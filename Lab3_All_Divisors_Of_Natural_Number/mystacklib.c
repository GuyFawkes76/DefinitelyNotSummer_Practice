//	Программа All_Divisors_Of_Natural_Number
//
//	Текущий файл mystacklib.с содержит тела связанных со стеками функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include <cstddef>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement * element = (stackElement *)malloc(sizeof(stackElement));
	element->value = inData;
	element->next = NULL;
	return element;
}

int getValue(stackElement * element) {
	//if (isEmpty(root))
	//	return INT_MIN;
	return element->value;
}

int isEmpty(stackElement * element) {
	return !element;
}

void push(stackElement ** prevElement, int value) {
	stackElement * element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement ** element) {
	//if (isEmpty(*root))
	//	return INT_MIN;
	int tempValue;
	stackElement * temp = *element;
	*element = (*element)->next;
	tempValue = temp->value;
	free(temp);
	return tempValue;
}

