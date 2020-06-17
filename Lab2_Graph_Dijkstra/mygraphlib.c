//	��������� Graph_Dijkstra
//
//	������� ���� mygraphlib.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include <climits>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

int * allocArray(int size) {
	int * temp;		//��������� ��� ��������� ������
	if (!(temp = malloc(size * sizeof(int)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	return temp;
}

//�������, ���������� ������ ��� ������� � ���������� �������� �� �������������. �� ���� ��������� ���������� ������.
int** allocateAdjMatrix(int verticesAmount) {
	int** allocMatrix = NULL;
	if (!(allocMatrix = malloc(verticesAmount * sizeof(int*)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	for (int i = 0; i < verticesAmount; i++) {
		if (!(allocMatrix[i] = malloc(verticesAmount * sizeof(int)))) {
			printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
			exit(0);
		}
		for (int j = 0; j < verticesAmount; j++) {
			allocMatrix[i][j] = INT_MAX;
		}
	}
	return allocMatrix;
}

void fillAdjMatrix(int** matrix, int verticesAmount) {
	printf("\n������� ������� ���������, �������� �������� ��������:\n");
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (!scanf("%d", &matrix[i][j])) {
				printf("�������� ������ �� �������� ����� ������. ��������� �������.");
				exit(0);
			}
			if (matrix[i][j] < 0) {
				printf("�������� �������� �� �������� � ������ ������������� �����. ��������� �������.");
				exit(0);
			}
		}
	}
}


void findCostsDijkstraAndPrint(int** adjMatrix, int verticesAmount, int startingVertix) {
	int seenVerticesCnt,		//������� ������ ����� �� ��� ������.
		curMin,					//������� ����������� ��� �����.
		flagAnyPath = 0,		//����, ����������, ������ �� �������� ����-������ ��� ���.
		nextVertixNum = 0;		//����� ��������� �������.
	int * costFromStart,		//��������� �� ������ � ������ ������.
		* previousVertix,		//��������� �� ������ ���������� ������.
		* visitedVerticesFlag;	//��������� �� ������ ������, ������������ ��������� ��� ����������� �������.

	//������� ���� �� INT_MAX, ����� ���������� ������� ����, ���������� ��� ��������� ��������.
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (adjMatrix[i][j] == 0) {
				adjMatrix[i][j] = INT_MAX;
			}
		}
	}

	//��������� ������ ��� costFromStart, previousVertix, visitedVerticesFlag.
	costFromStart = allocArray(verticesAmount);
	previousVertix = allocArray(verticesAmount);
	visitedVerticesFlag = allocArray(verticesAmount);

	//��������� ������� � ������ �����, ����������� ���������, � ���������� ���������.
	for (int i = 0; i < verticesAmount; i++) {
		costFromStart[i] = adjMatrix[startingVertix][i];
		previousVertix[i] = startingVertix;
		visitedVerticesFlag[i] = 0;
	}
	//�������� ��� ���� �� ������ �� ������ ����.
	costFromStart[startingVertix] = 0;
	//�������� ����� ���� ��� ����������.
	visitedVerticesFlag[startingVertix] = 1;
	//������ ������� ���������� ������ �� 1.
	seenVerticesCnt = 1;
	//��������� ���� �� ��� ���, ���� �� ������� ��� �������.
	while (seenVerticesCnt < verticesAmount - 1) {
		curMin = INT_MAX;

		//���������, ���� �� ���� � ������, ������� curMin.
		for (int i = 0; i < verticesAmount; i++) {
			if ((costFromStart[i] < curMin) && (!visitedVerticesFlag[i]))
			{
				curMin = costFromStart[i];
				nextVertixNum = i;
				flagAnyPath = 1;
			}
		}

		//�������� ��������� ������� ��� ����������.			
		visitedVerticesFlag[nextVertixNum] = 1;
		//����, ���� �� ����, ������, ��� ��� ���������.
		for (int i = 0; i < verticesAmount; i++) 
			if (!visitedVerticesFlag[i])
				if (curMin != INT_MAX && adjMatrix[nextVertixNum][i] != INT_MAX)
					if(curMin + adjMatrix[nextVertixNum][i] < costFromStart[i]) {	//��������� �� inf
						costFromStart[i] = curMin + adjMatrix[nextVertixNum][i];
						previousVertix[i] = nextVertixNum;
					}
		seenVerticesCnt++;
	}
	//������� ���� � ���������� �� ���� ������.
	printCostsDijkstra(verticesAmount, startingVertix, costFromStart, previousVertix, flagAnyPath);

	//����������� ������.
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
	printf("\n������� ����� ��������� �������: ");
	if (!scanf("%d", startingVertix)) {
		printf("�������� ������ �� �������� ����� ������.");
		exit(0);
	}
}

void getVerticesAmount(int* verticesAmount) {
	printf("������� ���������� ������ � �����: ");
	if (!scanf("%d", verticesAmount)) {
		printf("������� �� ����� �����, ��������� �������.");
		exit(0);
	}
	if (verticesAmount <= 1) {
		printf("���������� ������ ��� ���� ������ �� ����� ���� ������ ����. � ��������� ������ ������ �� ����� ������.");
		exit(0);
	}
}

void printCostsDijkstra(int verticesAmount, int * startingVertix, int * costFromStart, int * previousVertix, int flag) {
	if (flag)
		for (int i = 0; i < verticesAmount; i++) {
			if (i != startingVertix && costFromStart[i] != INT_MAX) {
				printf("\n��������� ���� �� ������� %d: %d", i, costFromStart[i]);
				printf("\n����=%d", i);
				int j = i;
				do {
					j = previousVertix[j];
					printf("<<%d", j);
				} while (j != startingVertix);
			}
		}
	else {
		printf("���� � ������ ������� �� �������.");
	}
}
