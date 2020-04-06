/*	Программа Граф_Конь (Graph_Horse)
*
*	Текущий файл mygraphlib.c содержит тела связанных с графом функций, необходимых для решения этой задачи.
*
*	Автор: Степаненко Кирилл
*	Группа: ИВТ-13БО
*/

#include "mygraphlib.h"
#include <stddef.h>

int getPosSteps(struct list* pQueueIn, struct list ** pQueueLast, int *** curField, int ranksAmount, int filesAmount) { //Функция, добавляющая возможные ходы в очередь.
	//Конь идёт вверх-влево.
	int newRank = pQueueIn->curRank - HORSEFIRSTOFFSET,											//Новый номер ряда.
		newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;	//Новый номер клетки.
	if ((newRank >= 0) &&  (newFile >= 0) && (newFile < filesAmount)) {							
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт вверх-вправо.
	newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт вправо-вверх.
	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт вправо-вниз.
	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт вниз-вправо.
	newRank = pQueueIn->curRank + HORSEFIRSTOFFSET;
	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт вниз-влево.
	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт влево-вниз.
	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//Конь идёт влево-вверх.
	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}
	return 0;
}

int checkStep(struct list ** pQueueLast, struct list * pQueueIn, int *** curField, int newRank, int newFile) {
	//Проверяем, посещалась ли уже клетка.
	if (curField[newRank][newFile][1] != VISITED) {
		//Если клетка не посещалась.
		if (curField[newRank][newFile][1] == NOTVISITED) {
			//Выделяем память для новой клетки в очереди
			if (!((*pQueueLast)->pNext = malloc(sizeof(struct list)))) {
				printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
				exit();
			}
			(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
			(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
			(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
			//Выделяем место под массив с путём
			if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	
				printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
				exit();
			}
			//Копируем путь из массива исходной клетки в массив новой.
			for (int i = 0; i < pQueueIn->curStep + 1; i++) {		
				(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
			}
			(*pQueueLast)->pNext->curRank = newRank;
			(*pQueueLast)->pNext->curFile = newFile;
			(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
			*pQueueLast = (*pQueueLast)->pNext;
			curField[newRank][newFile][1] = VISITED;
		}
		//Если клетка - цель.
		if (curField[newRank][newFile][1] == TARGET) {	
			printf("До указанной клетки найден следующий путь:");
			for (int i = 0; i < pQueueIn->curStep + 1; i++) {
				printf(" %d", pQueueIn->path[i]);
			}
			printf(" %d", curField[newRank][newFile][0]);
			return 1;
		}
	}
	return 0;
}

int clearQueue(struct list * pQueue) {		//Функция, очищающая очередь.
	struct list * pTemp;
	//Идём в начало очереди.
	for ( ; pQueue->pPrev; pQueue = pQueue->pPrev)	
		;
	//Очищаем очередь.
	for ( ; pQueue; ) {		
		free(pQueue->path);
		pTemp = pQueue->pNext;
		free(pQueue);
		pQueue = pTemp;
	}
}

struct list * createFirstElem(int *** field, int initRank, int initFile) {
	struct list* pQueue;
	if (!(pQueue = malloc(sizeof(struct list)))) {
		printf("Ошибка выделения памяти для очереди. Попробуйте закрыть ненужные приложения и повторить попытку.");
		exit(0);
	}
	pQueue->curRank = initRank;
	pQueue->curFile = initFile;
	pQueue->curStep = 0;
	pQueue->pPrev = NULL;
	pQueue->pNext = NULL;
	if (!(pQueue->path = malloc(sizeof(int)))) {
		printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
		exit(0);
	}
	pQueue->path[0] = field[initRank][initFile][0];
	return pQueue;
}
