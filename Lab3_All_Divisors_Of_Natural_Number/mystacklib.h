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
void pop(stackElement element); 
void push();

#endif	//MYSTACKLIB_H