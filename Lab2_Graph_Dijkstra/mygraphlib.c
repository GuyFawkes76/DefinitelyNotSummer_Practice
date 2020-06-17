//	Программа Graph_Dijkstra
//
//	Текущий файл mygraphlib.c содержит тела связанных с графом функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#include <climits>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

int * allocArray(int size) {
	int * temp;		//Указатель для выделения памяти
	if (!(temp = malloc(size * sizeof(int)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
		exit(0);
	}
	return temp;
}

//Функция, выделяющая память под матрицу и изменяющая значения на бесконечность. На вход принимает количество вершин.
int** allocateAdjMatrix(int verticesAmount) {
	int** allocMatrix = NULL;
	if (!(allocMatrix = malloc(verticesAmount * sizeof(int*)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
		exit(0);
	}
	for (int i = 0; i < verticesAmount; i++) {
		if (!(allocMatrix[i] = malloc(verticesAmount * sizeof(int)))) {
			printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторите попытку.");
			exit(0);
		}
		for (int j = 0; j < verticesAmount; j++) {
			allocMatrix[i][j] = INT_MAX;
		}
	}
	return allocMatrix;
}

void fillAdjMatrix(int** matrix, int verticesAmount) {
	printf("\nВведите матрицу смежности, разделяя элементы пробелом:\n");
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (!scanf("%d", &matrix[i][j])) {
				printf("Введённая строка не является целым числом. Повторите попытку.");
				exit(0);
			}
			if (matrix[i][j] < 0) {
				printf("Алгоритм Дейкстры не работает с рёбрами отрицательной длины. Повторите попытку.");
				exit(0);
			}
		}
	}
}


void findCostsDijkstraAndPrint(int** adjMatrix, int verticesAmount, int startingVertix) {
	int seenVerticesCnt,		//Сколько вершин графа мы уже обошли.
		curMin,					//Текущий минимальный вес ребра.
		flagAnyPath = 0,		//Флаг, указыващий, прошёл ли алгоритм куда-нибудь или нет.
		nextVertixNum = 0;		//Номер следующей вершины.
	int * costFromStart,		//Указатель на массив с весами вершин.
		* previousVertix,		//Указатель на массив предыдущих вершин.
		* visitedVerticesFlag;	//Указатель на массив флагов, обозначающих посещение или непосещение вершины.

	//Заменим нули на INT_MAX, чтобы получилась матрица веса, подходящая для алгоритма Дейкстры.
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (adjMatrix[i][j] == 0) {
				adjMatrix[i][j] = INT_MAX;
			}
		}
	}

	//Выделение памяти для costFromStart, previousVertix, visitedVerticesFlag.
	costFromStart = allocArray(verticesAmount);
	previousVertix = allocArray(verticesAmount);
	visitedVerticesFlag = allocArray(verticesAmount);

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
	while (seenVerticesCnt < verticesAmount - 1) {
		curMin = INT_MAX;

		//Проверяем, есть ли рёбра с длиной, меньшей curMin.
		for (int i = 0; i < verticesAmount; i++) {
			if ((costFromStart[i] < curMin) && (!visitedVerticesFlag[i]))
			{
				curMin = costFromStart[i];
				nextVertixNum = i;
				flagAnyPath = 1;
			}
		}

		//Помечаем следующую вершину как посещённую.			
		visitedVerticesFlag[nextVertixNum] = 1;
		//Ищем, есть ли путь, лучший, чем уже имеющийся.
		for (int i = 0; i < verticesAmount; i++) 
			if (!visitedVerticesFlag[i])
				if (curMin != INT_MAX && adjMatrix[nextVertixNum][i] != INT_MAX)
					if(curMin + adjMatrix[nextVertixNum][i] < costFromStart[i]) {	//Проверить на inf
						costFromStart[i] = curMin + adjMatrix[nextVertixNum][i];
						previousVertix[i] = nextVertixNum;
					}
		seenVerticesCnt++;
	}
	//Выводим путь и расстояние до всех вершин.
	printCostsDijkstra(verticesAmount, startingVertix, costFromStart, previousVertix, flagAnyPath);

	//Освобождаем память.
	free(costFromStart);
	free(previousVertix);
	free(visitedVerticesFlag);
}

void freeMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
}

void getStartingVertix(int* startingVertix) {
	printf("\nВведите номер стартовой вершины: ");
	if (!scanf("%d", startingVertix)) {
		printf("Введённая строка не является целым числом.");
		exit(0);
	}
}

void getVerticesAmount(int* verticesAmount) {
	printf("Введите количество вершин в графе: ");
	if (!scanf("%d", verticesAmount)) {
		printf("Введено не целое число, повторите попытку.");
		exit(0);
	}
	if (verticesAmount <= 1) {
		printf("Количество вершин для этой задачи не может быть меньше двух. В противном случае задача не имеет смысла.");
		exit(0);
	}
}

void printCostsDijkstra(int verticesAmount, int * startingVertix, int * costFromStart, int * previousVertix, int flag) {
	if (flag)
		for (int i = 0; i < verticesAmount; i++) {
			if (i != startingVertix && costFromStart[i] != INT_MAX) {
				printf("\nСтоимость пути до вершины %d: %d", i, costFromStart[i]);
				printf("\nПуть=%d", i);
				int j = i;
				do {
					j = previousVertix[j];
					printf("<<%d", j);
				} while (j != startingVertix);
			}
		}
	else {
		printf("Пути в другие вершины не найдены.");
	}
}
