/*	��������� ����_����
*
*	������� ���� mygraphlib.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ���� ������.
*
*	�����: ���������� ������
*	������: ���-13��
*/

#include "mygraphlib.h"
#include <stddef.h>

int getPosSteps(struct queue* pQueueIn, struct queue ** pQueueLast, int *** curField, int ranksAmount, int filesAmount) {
	//curField[pQueueIn->curRank][pQueueIn->curFile][1] = VISITED;

	int newRank = pQueueIn->curRank - HORSEFIRSTOFFSET,										//����� ����� ����.
		newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;	//����� ����� ������.
	if ((newRank >= 0) &&  (newFile >= 0) && (newFile < filesAmount)) { //���� ��� �����-�����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newFile = pQueueIn->curFile + HORSEFIRSTOFFSET * NEXTRANKOFFSET + HORSESECONDOFFSET;
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� �����-������.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc(((*pQueueLast)->pNext->curStep + 1) * sizeof(int)))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� ������-�����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� ������-����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� ����-������.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {
					printf(" %d", pQueueIn->path[i]);
				}
				printf(" %d", curField[newRank][newFile][0]);
				return 1;
			}
		}
	}

	newFile = pQueueIn->curFile - HORSEFIRSTOFFSET * NEXTRANKOFFSET - HORSESECONDOFFSET;
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� ����-�����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	if ((newRank < ranksAmount) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� �����-����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	if ((newRank >= 0) && (newFile >= 0) && (newFile < filesAmount)) { //���� ��� �����-�����.
		if (curField[newRank][newFile][1] != VISITED) {		//���������, ���������� �� ��� ������.
			if (curField[newRank][newFile][1] == NOTVISITED) {	//���� ������ �� ����������.
				if (!((*pQueueLast)->pNext = malloc(sizeof(struct queue)))) {	//�������� ������ ��� ����� ������ � �������
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				(*pQueueLast)->pNext->pPrev = *pQueueLast;		//��������� ����� ������� � ����������.
				(*pQueueLast)->pNext->pNext = NULL;		//�������� ���������.
				(*pQueueLast)->pNext->curStep = pQueueIn->curStep + 1;		//���������� ����� ����� ����.
				if (!((*pQueueLast)->pNext->path = malloc((((*pQueueLast)->pNext->curStep + 1) * sizeof(int))))) {	//�������� ����� ��� ������ � ����
					printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
					exit();
				}
				for (int i = 0; i < pQueueIn->curStep + 1; i++) {		//�������� ���� �� ������� �������� ������ � ������ �����.
					(*pQueueLast)->pNext->path[i] = pQueueIn->path[i];
				}
				(*pQueueLast)->pNext->curRank = newRank;
				(*pQueueLast)->pNext->curFile = newFile;
				(*pQueueLast)->pNext->path[(*pQueueLast)->pNext->curStep] = curField[(*pQueueLast)->pNext->curRank][(*pQueueLast)->pNext->curFile][0];
				*pQueueLast = (*pQueueLast)->pNext;
				curField[newRank][newFile][1] = VISITED;
			}
			if (curField[newRank][newFile][1] == TARGET) {	//���� ������ - ����.
				printf("�� ��������� ������ ������ ��������� ����:");
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
	for ( ; pQueue->pPrev; pQueue = pQueue->pPrev)	//��� � ������ �������.
		;
	for ( ; pQueue; ) {		//������� �������.
		free(pQueue->path);
		pTemp = pQueue->pNext;
		free(pQueue);
		pQueue = pTemp;
	}
}
