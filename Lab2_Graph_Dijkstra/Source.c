//	��������� Graph_Dijkstra
//
//	��������� ������������� ��� ����������� ��������� ������:
//
//	������������ ������ ��������������� ����, ������� ����� ������������� ��������� ����
//	����� ���������. ��������� ����������� ��������� ���� �� �������� ������� �� ���
//	���������. �������� ��������.
//
//	������� ���� source.c �������� ���� ��������� � ������ �������, ����������� ��� ������� ������ ������.
//
//	�����: ���������� ������
//	������: ���-13��
//
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

void main() {
	long int * costsList;	//��������� �� ������, ���������� ��������� ���� �� ���� ������ �� ������ �������.
	int ** adjMatrix;		//��������� �� ������� ��������� ���������������� ����������� �����.
	int verticesAmount;		//���������� ������ � �����.
	int startingVertix;		//����� ��������� �������.

	//���� ����� ���������� ������ � ����� � ������� ���������
	greetUser();
	getVerticesAmount(&verticesAmount);
	adjMatrix = allocateAdjMatrix(verticesAmount);
	fillAdjMatrix(adjMatrix, verticesAmount);

	findAllVertexCosts(adjMatrix);
}

int ** allocateAdjMatrix(int verticesAmount) {
	int ** allocMatrix = NULL;
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

		}
	}
	return allocMatrix;
}

int fillAdjMatrix(int ** matrix, int verticesAmount) {
	printf("������� ������� ���������, �������� �������� ��������:\n");
	for (int i = 0; i < verticesAmount; i++) {
		for (int j = 0; j < verticesAmount; j++) {
			if (!scanf("%d", &matrix[i][j])) {
				printf("�������� ������ �� �������� ����� ������. ��������� �������.");
				exit(0);
			}
		}
	}
}
int getVerticesAmount(int * verticesAmount) {
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
int getStartingNode() {

}
int greetUser() {
	printf("��� ����������� ��������� Graph_Dijkstra.\n\n"
		"��������� ������������� ��� ����������� ��������� ������:\n\n"
		"������������ ������ ��������������� ����, ������� ����� ������������� ��������� ����\n"
		"����� ���������. ��������� ����������� ��������� ���� �� �������� ������� �� ���\n"
		"���������. �������� ��������.\n"
		"�����: ���������� ������\n ������: ���-13��.\n\n");
}