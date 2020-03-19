/*	Программа Граф_Конь
*
*	Текущий файл mygraphlib.c содержит тела связанных с графом функций, необходимых для решения этой задачи.
*
*	Автор: Степаненко Кирилл
*	Группа: ИВТ-13БО
*/

#include "mygraphlib.h"
#include <stddef.h>

int getPosSteps(struct queue* pQueueIn, struct queue ** pQueueLast, int *** curField, int ranksAmount, int filesAmount) {
	//curField[pQueueIn->curRank][pQueueIn->curFile][1] = VISITED;

	int newRank = pQueueIn->curRank - HORSEFIRSTOFFSET,										//Новый номер ряда.
		newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;	//Новый номер клетки.
	if ((newRank >= 0) &&  (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вверх-влево.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вверх-вправо.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc(((*pQueueLast)->pNext->curStep + 1) * sizeof(int)))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вправо-вверх.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вправо-вниз.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newRank = pQueueIn->curRank + HORSEFIRSTOFFSET;
	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вниз-вправо.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт вниз-влево.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт влево-вниз.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //Конь идёт влево-вверх.
		if (curField[newRank][newFile][1] != VISITED) {		//Проверяем, посещалась ли уже клетка.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//Если клетка не посещалась.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//Выделяем память для новой клетки в очереди
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//Связываем новый элемент с предыдущим.
				(*pQueueLast)->pNext->pNext = NULL;		//Обнуляем указатель.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//Выставляем новый номер шага.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//Выделяем место под массив с путём
					printf("Ошибка выделения памяти. Попробуйте закрыть ненужные приложения и повторить попытку.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//Копируем путь из массива исходной клетки в массив новой.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//Если клетка - цель.
				printf("До указанной клетки найден следующий путь:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}
	return 0;
}

int clearQueue(struct queue * pQueue) {
	struct queue * pTemp;
	for ( ; pQueue->pPrev; pQueue = pQueue->pPrev)	//Идём в начало очереди.
		;
	for ( ; pQueue; ) {		//Очищаем очередь.
		free(pQueue->path);
		pTemp = pQueue->pNext;
		free(pQueue);
		pQueue = pTemp;
	}
}
