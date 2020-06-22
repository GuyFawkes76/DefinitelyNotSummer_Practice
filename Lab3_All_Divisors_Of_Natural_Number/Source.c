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


void main() {
	int number;					//�������� �����.
	double numberSqrt;			//���������� ������ �� ��������� ����� number.
	stackElement * divisors;	//��������� �� ������, ���������� ������ �������� ��������� - �� sqrt �� number.

	setlocale(LC_ALL, "RUS");	//������ ������� ���� ��� �������, ����� �� ���� ���������.
	
	greetUser();
	number = getNumber();
	findAndPrintDivisors(number);
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