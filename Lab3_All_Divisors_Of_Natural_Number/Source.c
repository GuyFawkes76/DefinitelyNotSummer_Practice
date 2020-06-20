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
#include <stdlib.h>
#include "mystacklib.h"

//�������, ����������� ������ �������� ����� ��������� - ����� ����� �� number
//stackElement* fillSecondStack(stackElement* element, int number);

void main() {
	int number;					//�������� �����.
	double numberSqrt;			//���������� ������ �� ��������� ����� number.
	stackElement * divisors;	//��������� �� ������, ���������� ������ �������� ��������� - �� sqrt �� number.
//	stackElement * secondHOD;	//��������� �� ������ �������� ��������� (second Half Of Divisors) - ����� sqrt �� number.

	setlocale(LC_ALL, "RUS");	//������ ������� ���� ��� �������, ����� �� ���� ���������.
	
	greetUser();
	number = getNumber();

	//numberSqrt = sqrt(number);
	divisors = fillStack(number, numberSqrt);
	printf("�������� ����� %d:", number);
	//printDivisors(divisors, secondHOD);
}

//stackElement * fillSecondStack(stackElement * element, int number) {
//	stackElement * curElement1;				//��������� �� ������� ������� ����������� ����� ���������.
//	stackElement * curElement2 = NULL;		//��������� �� ������� ������� ������������ ����� ���������
//	for (curElement1 = element; curElement1; curElement1 = curElement1->next) {
//		if (number / curElement1->value != curElement1->value) {
//			push(&curElement2, number / curElement1->value);
//		}
//	}
//	return curElement2;
//}

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