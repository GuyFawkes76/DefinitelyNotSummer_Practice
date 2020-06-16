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



void push(stackElement ** prevElement, int value) {
	stackElement* element;			//Указатель на новый создаваемый элемент списка
	element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement** element) {
	//if (isEmpty(*root))
	//	return INT_MIN;
	int tempValue;					//Указатель на временно хранящееся значение для его возврата.
	stackElement* temp;				//Указатель на элемент, который нужно удалить.
	temp = *element;
	*element = (*element)->next;
	tempValue = temp->value;
	free(temp);
	return tempValue;
}