//	Программа Graph_Dijkstra
//
//	Текущий файл mygraphlib.c содержит тела связанных с графом функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include <climits>
#include <malloc.h>
#include <stdlib.h>
#include "mygraphlib.h"

void findCostsDijkstraAndPrint(int** adjMatrix, int verticesAmount, int startingVertix) {
	int seenVerticesCnt,		//Сколько вершин графа мы уже обошли.
		curMin,					//Текущий минимальный вес ребра.
		nextVertixNum;			//Номер следующей вершины.
	int * costFromStart,		//Указатель на массив с весами вершин.
		* previousVertix,		//Указатель на массив предыдущих вершин.
		* visitedVerticesFlag;	//Указатель на массив флагов, обозначающих посещение или непосещение вершины.

	//Заменим нули на INT_MAX, чтобы получилась матрица веса, подходящая для алгоритма Дейкстры.
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (adjMatrix[i][j] == 0) {
				adjMatrix[i][j] = LARGE_INT;
			}
		}
	}

	//Выделение памяти для costFromStart, previousVertix, visitedVerticesFlag.
	if (!(costFromStart = malloc(verticesAmount * sizeof(int)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
		exit(0);
	}
	if (!(previousVertix = malloc(verticesAmount * sizeof(int)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
		exit(0);
	}
	if (!(visitedVerticesFlag = malloc(verticesAmount * sizeof(int)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
		exit(0);
	}
	//Заполняем массивы с весами путей, предыдущими вершинами, и посещёными вершинами.
	for (int i = 0; i < verticesAmount; i++) {
		costFromStart[i] = adjMatrix[startingVertix][i];
		previousVertix[i] = startingVertix;
		visitedVerticesFlag[i] = 0;
	}
	//Обнуляем вес пути от старта до самого себя.
	costFromStart[startingVertix] = 0;
	//Отмечаем старт пути как посещённый.
	visitedVerticesFlag[startingVertix] = 1;
	//Ставим счётчик посещённых вершин на 1.
	seenVerticesCnt = 1;
	//Выполняем цикл до тех пор, пока не посетим все вершины.
	while (seenVerticesCnt < (verticesAmount - 1)) {
		curMin = LARGE_INT;

		//Проверяем, есть ли рёбра с длиной, меньшей curMin.
		for (int i = 0; i < verticesAmount; i++) {
			if ((costFromStart[i] < curMin) && (!visitedVerticesFlag[i]))
			{
				curMin = costFromStart[i];
				nextVertixNum = i;
			}
		}

		//Помечаем следующую вершину как посещённую.			
		visitedVerticesFlag[nextVertixNum] = 1;
		//Ищем, есть ли путь, лучший, чем уже имеющийся.
		for (int i = 0; i < verticesAmount; i++) {
			if ((!visitedVerticesFlag[i]) && (curMin + adjMatrix[nextVertixNum][i] < costFromStart[i])) {
					costFromStart[i] = curMin + adjMatrix[nextVertixNum][i];
					previousVertix[i] = nextVertixNum;
			}
		}
		seenVerticesCnt++;
	}
	//Выводим путь и расстояние до всех вершин.
	for (int i = 0; i < verticesAmount; i++) {
		if ((i != startingVertix) && (costFromStart[i] != LARGE_INT)) {
			printf("\nСтоимость пути до вершины %d: %d", i, costFromStart[i]);
			printf("\nПуть=%d", i);
			int j = i;
			do {
				j = previousVertix[j];
				printf("<<%d", j);
			} while (j != startingVertix);
		}
	}
}
