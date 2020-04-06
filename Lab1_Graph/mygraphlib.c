/*	��������� ����_���� (Graph_Horse)
*
*	������� ���� mygraphlib.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ���� ������.
*
*	�����: ���������� ������
*	������: ���-13��
*/

#include "mygraphlib.h"
#include <stddef.h>

int getPosSteps(struct list* pQueueIn, struct list ** pQueueLast, int *** curField, int ranksAmount, int filesAmount) { //�������, ����������� ��������� ���� � �������.
	//���� ��� �����-�����.
	int newRank = pQueueIn->curRank - HORSEFIRSTOFFSET,											//����� ����� ����.
		newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;	//����� ����� ������.
	if ((newRank >= 0) &&  (newFile >= 0) && (newFile < filesAmount)) {							
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� �����-������.
	newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� ������-�����.
	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� ������-����.
	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET + HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� ����-������.
	newRank = pQueueIn->curRank + HORSEFIRSTOFFSET;
	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� ����-�����.
	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� �����-����.
	newRank = pQueueIn->curRank + HORSESECONDOFFSET;
	newFile = pQueueIn->curFile - HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}

	//���� ��� �����-�����.
	newRank = pQueueIn->curRank - HORSESECONDOFFSET;
	newFile = pQueueIn->curFile + HORSESECONDOFFSET * NEXTRANKOFFSET - HORSEFIRSTOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { 
		if (checkStep(pQueueLast, pQueueIn, curField, newRank, newFile))
			return 1;
	}
	return 0;
}

int checkStep(struct list ** pQueueLast, struct list * pQueueIn, int *** curField, int newRank, int newFile) {
	//���������, ���������� �� ��� ������.
	if (curField[newRank][newFile][1] != VISITED) {
		//���� ������ �� ����������.
		if (curField[newRank][newFile][1] == NOTVISITED) {
			//�������� ������ ��� ����� ������ � �������
			if (!((*pQueueLast)->pNext = malloc(sizeof(struct list)))) {
				printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
				exit();
			}
			(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
			(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
			(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
			//�������� ����� ��� ������ � ����
			if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	
				printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
				exit();
			}
			//�������� ���� �� ������� �������� ������ � ������ �����.
			for (int i = 0; i < pQueueIn->curStep + 1; i++) {		
				(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
			}
			(*pQueueLast)->pNext->curRank = newRank;
			(*pQueueLast)->pNext->curFile = newFile;
			(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
			*pQueueLast = (*pQueueLast)->pNext;
			curField[newRank][newFile][1] = VISITED;
		}
		//���� ������ - ����.
		if (curField[newRank][newFile][1] == TARGET) {	
			printf("�� ��������� ������ ������ ��������� ����:");
			for (int i = 0; i < pQueueIn->curStep + 1; i++) {
				printf(" %d", pQueueIn->path[i]);
			}
			printf(" %d", curField[newRank][newFile][0]);
			return 1;
		}
	}
	return 0;
}

int clearQueue(struct list * pQueue) {		//�������, ��������� �������.
	struct list * pTemp;
	//��� � ������ �������.
	for ( ; pQueue->pPrev; pQueue = pQueue->pPrev)	
		;
	//������� �������.
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
		printf("������ ��������� ������ ��� �������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	pQueue->curRank = initRank;
	pQueue->curFile = initFile;
	pQueue->curStep = 0;
	pQueue->pPrev = NULL;
	pQueue->pNext = NULL;
	if (!(pQueue->path = malloc(sizeof(int)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	pQueue->path[0] = field[initRank][initFile][0];
	return pQueue;
}
