//	��������� All_Divisors_Of_Natural_Number
//
//	������� ���� mystacklib.� �������� ���� ��������� �� ������� �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include <math.h>
#include <stdio.h>
#include "mystacklib.h"

stackElement * createElement(int inData) {
	struct stackElement* element;							//��������� �� ����� ����������� ������� ������.
	element = (stackElement*)malloc(sizeof(stackElement));
	element->value = inData;
	element->next = NULL;
	return element;
}

void findAndPrintDivisors(int number) {
	int divisor;						//������� �����, ����������� �� ��������.
	double numberSqrt = sqrt(number);
	stackElement* curElement = NULL;	//��������� �� ������� �������.
	for (divisor = numberSqrt; divisor > 0; divisor--) {	//���������, �������� �� ����� ���������.
		if (number % divisor == 0) {
			push(&curElement, divisor);
			printf(" %d", divisor);
		}
	}
	return curElement;
}

int getNumber() {
	int number;
	printf("������� ����������� ����� n, ��� �������� ��������� ����� ��� ��������: ");
	if (!scanf("%d", &number)) {
		printf("�������� ������ �� �������� ����������� ������, ��������� �������.");
		exit(0);
	}
	if (number <= 0) {
		printf("�������� ����� �� �������� �����������, ��������� �������.");
		exit(0);
	}
	return number;
}

int getValue(stackElement* element) {
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

//void printDivisors(stackElement* firstHOD, stackElement* secondHOD) {
//	stackElement* curElement;				//��������� �� ������� ������� ����� (������� ������, ����� �������) ���������.
//	for (curElement = firstHOD; curElement; ) {
//		printf(" %d", pop(&curElement));
//	}
//	for (curElement = secondHOD; curElement; ) {
//		printf(" %d", pop(&curElement));
//	}
//	printf(".");
//}