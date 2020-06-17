//	��������� Graph_Dijkstra
//
//	������� ���� mygraphlib.h �������� ���������� ��������� � ������ ������� � ����� ������, ����������� ��� ������� ������ ������.
//	������ ���������� �������� �� ������������� ����� ��� ������� ���������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#ifndef MYGRAPHLIB_H
#define MYGRAPHLIB_H

//�������, ���������� ������ ��� ������ ����� �����. 
//�� ���� ��������� ��������� ������ �������, ���������� ��������� �� ���������� ������.
int * allocArray(int size);

//�������, ���������� ������ ��� ������� � ���������� �������� �� �������������. 
//�� ���� ��������� ���������� ������. ���������� ��������� �� ���������� ������.
int ** allocateAdjMatrix(int verticesAmount);

//�������, ����������� �������.
void fillAdjMatrix(int ** matrix, int verticesAmount);


//�������, ��������� ���� � �� ���� �� ���� ������ �����.
//�� ���� ��������� ������� ���������, ���������� ������ � ����� ��������� �������.
void findCostsDijkstraAndPrint(int ** adjMatrix, int verticesAmount, int startingVertix);

//�������, ������������� ������ �� �������.
//�� ���� ��������� ��������� �� ������� � ������.
void freeMatrix(int ** matrix, int size);

//�������, ����������� ����� ��������� �������.
void getStartingVertix(int* startingVertix);

//�������, ����������� ���������� ������.
//�� ���� ��������� ��������� �� ���������� ��� ����������.
void getVerticesAmount(int * verticesAmount);

//�������, ��������� ���������� ������.
void printCostsDijkstra(int verticesAmount, int* startingVertix, int* costFromStart, int* previousVertix, int flag);
#endif	//MYGRAPHLIB_H