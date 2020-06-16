//	��������� All_Divisors_Of_Natural_Number
//
//	��������� ������������ ��� ���������� ���������� �������:
//
//		��� ���������� ��������� ������������ ����� ���������� �������� ��������� ���������
//		����� ����������� ���������, ���� ������, ��� � ������� �������� d ����� n, ��
//		������������ ���������� ������ �� n, ���� ������������� ��� ��������. 
//		��������, ���� n = 30, ���������� ����� �������� 1, 2, 3, 5 
//		(����� ����� ����������� ����� �� 30 ����� 5), � ��� ������ �����������.
//		�������� ���������, � ������� ��� �������� ��������� ����� n ����� ���������� � �������
//		�����������(��� �������������� ����������, �� � ������������� ������).
//
//		������� ���� Source.c �������� � ���� �������� ������� main � ��������� ���� ����������� ������.
//		
//	�����: ���������� ������
//	������: ���-13��
//
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include "mystacklib.h"

//�������, ����������� ������ �������� ����� ��������� - �� ����� �� number
stackElement* fillFirstStack(int number, double numberSqrt);
//�������, ����������� ������ �������� ����� ��������� - ����� ����� �� number
stackElement* fillSecondStack(stackElement* element, int number);

void main() {
	int number;					//�������� �����.
	double numberSqrt;			//���������� ������ �� ��������� ����� number.
	stackElement * firstHOD;	//��������� �� ������ �������� ��������� (first Half Of Divisors) - �� sqrt �� number.
	stackElement * secondHOD;	//��������� �� ������ �������� ��������� (second Half Of Divisors) - ����� sqrt �� number.

	setlocale(LC_ALL, "RUS");
	
	greetUser();
	printf("������� ����������� ����� n, ��� �������� ��������� ����� ��� ��������: ");
	if (!scanf("%d", &number)) {
		printf("�������� ������ �� �������� ����������� ������, ��������� �������.");
		return;
	}
	if (number <= 0) {
		printf("�������� ����� �� �������� �����������, ��������� �������.");
		return;
	}
	numberSqrt = sqrt(number);
	firstHOD = fillFirstStack(number, numberSqrt);
	secondHOD = fillSecondStack(firstHOD, number);
	printf("�������� ����� %d:", number);
	popAndPrintDivisors(firstHOD, secondHOD);
}

stackElement * fillFirstStack(int number, double numberSqrt) {
	int divisor;						//������� �����, ����������� �� ��������.
	stackElement * curElement = NULL;	//��������� �� ������� �������.
	for (divisor = numberSqrt; divisor > 0; divisor--) {	//���������, �������� �� ����� ���������.
		if (number % divisor == 0) {
			push(&curElement, divisor);
		}
	}
	return curElement;
}

stackElement * fillSecondStack(stackElement * element, int number) {
	stackElement * curElement1;				//��������� �� ������� ������� ����������� ����� ���������.
	stackElement * curElement2 = NULL;		//��������� �� ������� ������� ������������ ����� ���������
	for (curElement1 = element; curElement1; curElement1 = curElement1->next) {
		if (number / curElement1->value != curElement1->value) {
			push(&curElement2, number / curElement1->value);
		}
	}
	return curElement2;
}

int greetUser() {	//�������, ��������� ����������� � �������� ������ ���������.
	printf("��� ����������� ��������� All_Divisors_Of_Natural_Number.\n\n"
		"��������� ������������ ��� ���������� ������� ��� ��������� ��������:\n\n"
		"��� ���������� ��������� ������������ ����� ���������� �������� ��������� ���������\n"
		"����� ����������� ���������, ���� ������, ��� � ������� �������� d ����� n, ��\n"
		"������������ ���������� ������ �� n, ���� ������������� ��� ��������.\n"
		"��������, ���� n = 30, ���������� ����� �������� 1, 2, 3, 5\n"
		"(����� ����� ����������� ����� �� 30 ����� 5), � ��� ������ �����������.\n\n"
		"�������:\n\n"
		"������� ��� �������� ��������� ����� n � ������� �����������\n"
		"(��� �������������� ����������, �� � �������������� ������).\n\n"
		"�����: ���������� ������\n ������: ���-13��.\n\n");
}

int popAndPrintDivisors(stackElement * firstHOD, stackElement * secondHOD) {
	stackElement * curElement;				//��������� �� ������� ������� ����� (������� ������, ����� �������) ���������.
	for (curElement = firstHOD; curElement; ) {
		printf(" %d", pop(&curElement));
	}
	for (curElement = secondHOD; curElement; ) {
		printf(" %d", pop(&curElement));
	}
	printf(".");
}