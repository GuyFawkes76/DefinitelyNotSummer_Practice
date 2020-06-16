//	Программа Graph_Dijkstra
//
//	Текущий файл mygraphlib.h содержит декларации связанных с графом функций и типов данных, необходимых для решения данной задачи.
//	Данная реализация основана на представлении графа как матрицы смежности.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#ifndef MYGRAPHLIB_H
#define MYGRAPHLIB_H

typedef struct adjacencyMatrix {
	int ** matrix;		//Матрица смежности.
	int vertexAmount;	//Количество вершин в графе.
} adjacencyMatrix;

void findAllAdjCosts(adjacencyMatrix * adjMatix, long int* costsList, int curVertex);
void findAllVertexCosts(adjacencyMatrix * adjMatrix);
int findShortestExcept(adjacencyMatrix * adjMatrix, int curVertex, int exclVertex);
#endif	//MYGRAPHLIB_H