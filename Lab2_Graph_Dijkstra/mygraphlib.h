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

//Функция, выделяющая память под массив целых чисел. 
//На вход принимает требуемый размер массива, возвращает указатель на выделенную память.
int * allocArray(int size);

//Функция, выделяющая память под матрицу и изменяющая значения на бесконечность. 
//На вход принимает количество вершин. Возвращает указатель на выделенную память.
int ** allocateAdjMatrix(int verticesAmount);

//Функция, считывающая матрицу.
void fillAdjMatrix(int ** matrix, int verticesAmount);


//Функция, находящая пути и их веса до всех вершин графа.
//На вход принимает матрицу смежности, количество вершин и номер стартовой вершины.
void findCostsDijkstraAndPrint(int ** adjMatrix, int verticesAmount, int startingVertix);

//Функция, освобождающая память от матрицы.
//На вход принимает указатель на матрицу и размер.
void freeMatrix(int ** matrix, int size);

//Функция, считывающая номер стартовой вершины.
void getStartingVertix(int* startingVertix);

//Функция, считывающая количество вершин.
//На вход принимает указатель на переменную для считывания.
void getVerticesAmount(int * verticesAmount);

//Функция, выводящая результаты работы.
void printCostsDijkstra(int verticesAmount, int* startingVertix, int* costFromStart, int* previousVertix, int flag);
#endif	//MYGRAPHLIB_H