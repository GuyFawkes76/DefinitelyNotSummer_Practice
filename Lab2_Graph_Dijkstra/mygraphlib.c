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

void findCostsDijkstra(int** adjMatrix, int verticesAmount, int startingVertix) {
	int seenVerticesCnt,		//������� ������ ����� �� ��� ������.
		curMin,
		nextVertixNum;
	int * costFromStart,
		* previousVertix,
		* visitedVerticesFlag;
	//������� ���� �� INT_MAX, ����� ���������� ������� ����, ���������� ��� ��������� ��������.
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (adjMatrix[i][j] == 0) {
				adjMatrix[i][j] = INT_MAX;
			}
		}
	}

	//initialize pred[],distance[] and visited[]
	for (int i = 0; i < verticesAmount; i++)
	{
		costFromStart[i] = adjMatrix[startingVertix][i];
		previousVertix[i] = startingVertix;
		visitedVerticesFlag[i] = 0;
	}

	costFromStart[startingVertix] = 0;
	visitedVerticesFlag[startingVertix] = 1;
	seenVerticesCnt = 1;

	while (seenVerticesCnt < (verticesAmount - 1))
	{
		curMin = INT_MAX;

		//nextnode gives the node at minimum distance
		for (int i = 0; i < verticesAmount; i++)
			if ((costFromStart[i] < curMin) && (!visitedVerticesFlag[i]))
			{
				curMin = costFromStart[i];
				nextVertixNum = i;
			}

		//check if a better path exists through nextnode			
		visitedVerticesFlag[nextVertixNum] = 1;
		for (int i = 0; i < verticesAmount; i++)
			if (!visitedVerticesFlag[i])
				if (curMin + adjMatrix[nextVertixNum][i] < costFromStart[i])
				{
					costFromStart[i] = curMin + adjMatrix[nextVertixNum][i];
					previousVertix[i] = nextVertixNum;
				}
		seenVerticesCnt++;
	}
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