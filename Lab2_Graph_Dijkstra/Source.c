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
#include <locale.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

void main() {
	int ** adjMatrix;		//Указатель на матрицу смежности ориентированного взвешенного графа.
	int verticesAmount;		//Количество вершин в графе.
	int startingVertix;		//Номер стартовой вершины.

	setlocale(LC_ALL, "RUS");

	//Блок ввода количества вершин в графе и матрицы смежности.
	greetUser();
	getVerticesAmount(&verticesAmount);
	adjMatrix = allocateAdjMatrix(verticesAmount);
	fillAdjMatrix(adjMatrix, verticesAmount);
	getStartingVertix(&startingVertix);
	//Вызов функции, осуществляющей поиск путей и их вывод.
	findCostsDijkstraAndPrint(adjMatrix, verticesAmount, startingVertix);
	//Освобождаем память.
	freeMatrix(adjMatrix, verticesAmount);
}

//Функция, выдающая информацию о программе и приветствующая пользователя.
int greetUser() {
	printf("Вас привествует программа Graph_Dijkstra.\n\n"
		"Программа предназначена для ввыполнения следующей задачи:\n\n"
		"Пользователь задает ориентированный граф, каждому ребру приписывается стоимость пути\n"
		"между вершинами. Вычислить минимальную стоимость пути из заданной вершины во все\n"
		"остальные. Алгоритм Дейкстры.\n"
		"Автор: Степаненко Кирилл\n Группа: ИВТ-13БО.\n\n");
}