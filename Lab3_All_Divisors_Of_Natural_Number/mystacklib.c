//	��������� All_Divisors_Of_Natural_Number
//
//	������� ���� mystacklib.� �������� ���� ��������� �� ������� �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include <stdio.h>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement* element;							//��������� �� ����� ����������� ������� ������.
	element = (stackElement*)malloc(sizeof(stackElement));
	element->value = inData;
	element->next = NULL;
	return element;
}



void push(stackElement ** prevElement, int value) {
	stackElement* element;			//��������� �� ����� ����������� ������� ������
	element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement** element) {
	//if (isEmpty(*root))
	//	return INT_MIN;
	int tempValue;					//��������� �� �������� ���������� �������� ��� ��� ��������.
	stackElement* temp;				//��������� �� �������, ������� ����� �������.
	temp = *element;
	*element = (*element)->next;
	tempValue = temp->value;
	free(temp);
	return tempValue;
}