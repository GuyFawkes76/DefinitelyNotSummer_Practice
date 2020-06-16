//	��������� All_Divisors_Of_Natural_Number
//
//	������� ���� mystacklib.h �������� ���������� ��������� �� ������� ������� � ����� ������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//

#ifndef MYSTACKLIB_H
#define MYSTACKLIB_H
typedef struct stackElement {
	int value;
	struct stackElement * next;
} stackElement;

stackElement* createElement(int inData);
int getValue(stackElement* element);
void push(stackElement** prevElement, int value);
int pop(stackElement** element);

#endif	//MYSTACKLIB_H