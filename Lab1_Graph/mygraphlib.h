//	Программа Граф_Конь (Graph_Horse)
//
//	Текущий файл mygraphlib.h содержит декларации связанных с графом функций и типов данных, необходимых для решения этой задачи.
//
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//

#ifndef MYGRAPHLIB_H
#define MYGRAPHLIB_H
#define HORSEFIRSTOFFSET 2		//Количество клеток, которое конь ходит "вперёд".
#define HORSESECONDOFFSET 1		//Количество клеток, которое конь ходит "в сторону".
#define NEXTRANKOFFSET 1		//Количество клеток, на которое смещается каждый следующий ряд относительно предыдущего.
#define NOTVISITED 0			//Константа, обозначающая непосещённую клетку
#define VISITED 1				//Константа, обозначающая посещённую или запрещённую клетку
#define TARGET 2				//Константа, обозначающая целевую клетку
struct queue {		//Список, представляющий собой почти "очередь".
	int curRank;	//Номер текущего ряда
	int curFile;	//Номер текущей клетки
	int curStep;	//Номер шага
	int* path;		//Массив целых чисел, показывающих путь к текущей клетке
	struct queue * pNext;	//Указатель на предыдущий элемент в очереди
	struct queue * pPrev;	//Указатель на следующий элемент в очереди
};

int getPosSteps(struct queue * pQueue, struct queue ** pQueueLast, int *** curField, int ranksAmount, int filesAmount);
int clearQueue(struct queue * pQueue);

#endif