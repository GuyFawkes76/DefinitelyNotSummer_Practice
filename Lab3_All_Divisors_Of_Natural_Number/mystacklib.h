//	��������� All_Divisors_Of_Natural_Number
//
//	������� ���� mystacklib.h �������� ���������� ��������� �� ������� ������� � ����� ������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//

#ifndef MYSTACKLIB_H
#define MYSTACKLIB_H
typedef struct stackElement {	//���������, �������������� ����� ������� �����
	int value;					//��������, ���������� � �������� �����
	struct stackElement * next;	//��������� �� ��������� ������� �����
} stackElement;					//������� typedef, ����� �� ������ ����� struct

//�������, ��������� ����� ������� �����. �� ���� ��������� ��������, ������� �������� � �������. ���������� ��������� �� ��������� �������.
//!!!�� �������� ������� ������, � ������ ����!!!
stackElement* createElement(int inData);

//�������, ����������� ������ �������� ����� ��������� - �� ����� �� number
stackElement* fillStack(int number, double numberSqrt);

//�������, ������������� ���� ������������ ����� � �������. ��� �������� ������������ ����� ���������� ���.
int getNumber();

//�������, ������������ �������� ��������.
int getValue(stackElement* element);

//�������, �����������, ���������� �� ������� ������.
int isEmpty(stackElement* element);

//�������, ����������� ����� ������� � ����. �� ���� ��������� ��������� �� ��������� �� ������� ������� � ��������, ������� �������� � �������.
//�������� createElement, !!!�� �������� ������� ������, ������� pop!!!
void push(stackElement** prevElement, int value);

//�������, ��������� ������� �� ����� � ������������ ��� ��������. �� ���� ��������� ��������� �� ��������� �� �������.
int pop(stackElement** element);

//�������, ��������� ��������
void printDivisors(stackElement* firstHOD, stackElement* secondHOD);
#endif	//MYSTACKLIB_H
