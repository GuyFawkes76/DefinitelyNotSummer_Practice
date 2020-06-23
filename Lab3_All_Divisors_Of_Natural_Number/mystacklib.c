//	��������� All_Divisors_Of_Natural_Number
//
//	������� ���� mystacklib.� �������� ���� ��������� �� ������� �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement* element;							//��������� �� ����� ����������� ������� ������.
	if (!(element = (stackElement*)malloc(sizeof(stackElement)))) {
		printf("������ ��������� ������. �������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	element->value = inData;
	element->next = NULL;
	return element;
}

stackElement * findAndPrintDivisors(int number) {
	int divisor;						//������� �����, ����������� �� ��������.
	double numberSqrt = sqrt(number);
	stackElement * curElement = NULL;	//��������� �� ������� �������.
	printf("�������� ����� %d:", number);
	for (divisor = 1; divisor <= numberSqrt; divisor++) {	//���������, �������� �� ����� ���������.
		if (number % divisor == 0) {
			push(&curElement, divisor);
			printf(" %d", divisor);
		}
	}
	for ( ; !isEmpty(curElement); ) {
		if (getValue(curElement) != numberSqrt) {
			printf(" %d", number/pop(&curElement));
		}
		else
			pop(&curElement);
	}
	printf(".");
	return curElement;
}

int freeStack(stackElement * element) {
	for ( ; !isEmpty(element); )
		pop(&element);
	return 0;
}

int getNumber() {
	int number;
	printf("������� ����������� ����� n, ��� �������� ��������� ����� ��� ��������: ");
	if (!scanf("%d", &number)) {
		printf("�������� ������ �� �������� ����������� ������, ��������� �������.");
		exit(0);
	}
	if (number <= 0) {
		printf("�������� ����� ��� �� �������� �����������, ��� ������ %d, ��������� �������.", INT_MAX);
		exit(0);
	}
	return number;
}

int getValue(stackElement * element) {
	if (isEmpty(element))	//���� �������� �� ����������, �� ���������� 0, ������ ��� 0 - ������, � �� �� ����� ���� ���������.
		return 0;
	return element->value;
}

int isEmpty(stackElement * element) {
	return !element;
}

void push(stackElement ** prevElement, int value) {
	stackElement* element;			//��������� �� ����� ����������� ������� ������
	element = createElement(value);
	element->next = *prevElement;
	*prevElement = element;
}

int pop(stackElement ** element) {
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
