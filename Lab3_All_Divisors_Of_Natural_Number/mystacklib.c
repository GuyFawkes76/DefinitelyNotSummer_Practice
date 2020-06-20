//	Программа All_Divisors_Of_Natural_Number
//
//	Текущий файл mystacklib.с содержит тела связанных со стеками функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include <stdio.h>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement* element;							//Указатель на новый создаваемый элемент списка.
	element = (stackElement*)malloc(sizeof(stackElement));
	element->value = inData;
	element->next = NULL;
	return element;
}

int isEmpty(stackElement * element) {
	return !element;
}

int getValue(stackElement * element) {
	if (isEmpty(element))	//Если элемента не существует, то возвращаем 0, потому что 0 - удобно, и он не может быть делителем.
		return 0;
	return element->value;
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