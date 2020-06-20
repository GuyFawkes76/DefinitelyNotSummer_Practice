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

int isEmpty(stackElement * element) {
	return !element;
}

int getValue(stackElement * element) {
	if (isEmpty(element))	//���� �������� �� ����������, �� ���������� 0, ������ ��� 0 - ������, � �� �� ����� ���� ���������.
		return 0;
	return element->value;
}

void push(stackElement ** prevElement, int value) {
	stackElement* element;			//��������� �� ����� ����������� ������� ������
	element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement** element) {
	if (isEmpty(*element))	//���� �������� �� ����������, �� ���������� 0, ������ ��� 0 - ������, � �� �� ����� ���� ���������.
		return 0;
	int tempValue;					//��������� �� �������� ���������� �������� ��� ��� ��������.
	stackElement* temp;				//��������� �� �������, ������� ����� �������.
	temp = *element;
	*element = (*element)->next;
	tempValue = getValue(temp);
	free(temp);
	return tempValue;
}