//	Программа Graph_Dijkstra
//
//	Текущий файл mygraphlib.c содержит тела связанных с графом функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include "mygraphlib.h"
#include <climits>

void findAllAdjCosts(adjacencyMatrix * adjMatix, long int * costsList, int curVertex) {
	int curCheckedVertex;	//Номер вершины, стоимость которой проверяется в текущий момент. (!=curVertex)

}

void findAllVertexCosts(adjacencyMatrix * adjMatrix) {

}

int findShortestExcept(adjacencyMatrix * adjMatrix, int curVertex, int exclVertex) {
	int curMin = INT_MAX;			//Текущая найденная минимальная стоимость.
	int curMinVertex = curVertex;	//Номер вершины с curMin.
	for (int i = 0; i < adjMatrix->vertexAmount; i++) {
		if ((adjMatrix->matrix[curVertex][i] != -1) && 
			(adjMatrix->matrix[curVertex][i] < curMin) &&
			(i != exclVertex)) {
			curMin = adjMatrix->matrix[curVertex][i];
			curMinVertex = i;
		}
	}
}