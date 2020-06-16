//	Программа Graph_Dijkstra
//
//	Программа предназначена для ввыполнения следующей задачи:
//
//	Пользователь задает ориентированный граф, каждому ребру приписывается стоимость пути
//	между вершинами. Вычислить минимальную стоимость пути из заданной вершины во все
//	остальные. Алгоритм Дейкстры.
//
//	Текущий файл source.c содержит тела связанных с графом функций, необходимых для решения данной задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

void main() {
	long int * costsList;	//Указатель на массив, содержащий стоимость пути до всех вершин из данной вершины.
	int ** adjMatrix;		//Указатель на матрицу смежности ориентированного взвешенного графа.
	int verticesAmount;		//Количество вершин в графе.
	int startingVertix;		//Номер стартовой вершины.

	//Блок ввода количества вершин в графе и матрицы смежности
	greetUser();
	getVerticesAmount(&verticesAmount);
	adjMatrix = allocateAdjMatrix(verticesAmount);
	fillAdjMatrix(adjMatrix, verticesAmount);

	findAllVertexCosts(adjMatrix);
}

int ** allocateAdjMatrix(int verticesAmount) {
	int ** allocMatrix = NULL;
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

		}
	}
	return allocMatrix;
}

int fillAdjMatrix(int ** matrix, int verticesAmount) {
	printf("Введите матрицу смежности, разделяя элементы пробелом:\n");
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (!scanf("%d", &matrix[i][j])) {
				printf("Введённая строка не является целым числом. Повторите попытку.");
				exit(0);
			}
		}
	}
}
int getVerticesAmount(int * verticesAmount) {
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
int getStartingNode() {

}
int greetUser() {
	printf("Вас привествует программа Graph_Dijkstra.\n\n"
		"Программа предназначена для ввыполнения следующей задачи:\n\n"
		"Пользователь задает ориентированный граф, каждому ребру приписывается стоимость пути\n"
		"между вершинами. Вычислить минимальную стоимость пути из заданной вершины во все\n"
		"остальные. Алгоритм Дейкстры.\n"
		"Автор: Степаненко Кирилл\n Группа: ИВТ-13БО.\n\n");
}