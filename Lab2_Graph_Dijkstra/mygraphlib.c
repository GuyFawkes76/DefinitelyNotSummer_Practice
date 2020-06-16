//	��������� Graph_Dijkstra
//
//	������� ���� mygraphlib.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include "mygraphlib.h"
#include <climits>

void findAllAdjCosts(adjacencyMatrix * adjMatix, long int * costsList, int curVertex) {
	int curCheckedVertex;	//����� �������, ��������� ������� ����������� � ������� ������. (!=curVertex)

}

void findAllVertexCosts(adjacencyMatrix * adjMatrix) {

}

int findShortestExcept(adjacencyMatrix * adjMatrix, int curVertex, int exclVertex) {
	int curMin = INT_MAX;			//������� ��������� ����������� ���������.
	int curMinVertex = curVertex;	//����� ������� � curMin.
	for (int i = 0; i < adjMatrix->vertexAmount; i++) {
		if ((adjMatrix->matrix[curVertex][i] != -1) && 
			(adjMatrix->matrix[curVertex][i] < curMin) &&
			(i != exclVertex)) {
			curMin = adjMatrix->matrix[curVertex][i];
			curMinVertex = i;
		}
	}
}