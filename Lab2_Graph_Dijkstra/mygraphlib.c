//	��������� Graph_Dijkstra
//
//	������� ���� mygraphlib.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#include <climits>
#include <malloc.h>
#include <stdlib.h>
#include "mygraphlib.h"

void findCostsDijkstraAndPrint(int** adjMatrix, int verticesAmount, int startingVertix) {
	int seenVerticesCnt,		//������� ������ ����� �� ��� ������.
		curMin,					//������� ����������� ��� �����.
		nextVertixNum;			//����� ��������� �������.
	int * costFromStart,		//��������� �� ������ � ������ ������.
		* previousVertix,		//��������� �� ������ ���������� ������.
		* visitedVerticesFlag;	//��������� �� ������ ������, ������������ ��������� ��� ����������� �������.

	//������� ���� �� INT_MAX, ����� ���������� ������� ����, ���������� ��� ��������� ��������.
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (adjMatrix[i][j] == 0) {
				adjMatrix[i][j] = LARGE_INT;
			}
		}
	}

	//��������� ������ ��� costFromStart, previousVertix, visitedVerticesFlag.
	if (!(costFromStart = malloc(verticesAmount * sizeof(int)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	if (!(previousVertix = malloc(verticesAmount * sizeof(int)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
	if (!(visitedVerticesFlag = malloc(verticesAmount * sizeof(int)))) {
		printf("������ ��������� ������. ���������� ������� �������� ���������� � ��������� �������.");
		exit(0);
	}
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
	while (seenVerticesCnt < (verticesAmount - 1)) {
		curMin = LARGE_INT;

		//���������, ���� �� ���� � ������, ������� curMin.
		for (int i = 0; i < verticesAmount; i++) {
			if ((costFromStart[i] < curMin) && (!visitedVerticesFlag[i]))
			{
				curMin = costFromStart[i];
				nextVertixNum = i;
			}
		}

		//�������� ��������� ������� ��� ����������.			
		visitedVerticesFlag[nextVertixNum] = 1;
		//����, ���� �� ����, ������, ��� ��� ���������.
		for (int i = 0; i < verticesAmount; i++) {
			if ((!visitedVerticesFlag[i]) && (curMin + adjMatrix[nextVertixNum][i] < costFromStart[i])) {
					costFromStart[i] = curMin + adjMatrix[nextVertixNum][i];
					previousVertix[i] = nextVertixNum;
			}
		}
		seenVerticesCnt++;
	}
	//������� ���� � ���������� �� ���� ������.
	for (int i = 0; i < verticesAmount; i++) {
		if (i != startingVertix) {
			printf("\n��������� ���� �� ������� %d=%d", i, costFromStart[i]);
			printf("\n����=%d", i);
			int j = i;
			do
			{
				j = previousVertix[j];
				printf("<<%d", j);
			} while (j != startingVertix);
		}
	}
}
