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

typedef struct adjacencyMatrix {
	int ** matrix;		//������� ���������.
	int vertexAmount;	//���������� ������ � �����.
} adjacencyMatrix;

void findAllAdjCosts(adjacencyMatrix * adjMatix, long int* costsList, int curVertex);
void findAllVertexCosts(adjacencyMatrix * adjMatrix);
int findShortestExcept(adjacencyMatrix * adjMatrix, int curVertex, int exclVertex);
#endif	//MYGRAPHLIB_H