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
#include <locale.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "mygraphlib.h"

void main() {
	int ** adjMatrix;		//��������� �� ������� ��������� ���������������� ����������� �����.
	int verticesAmount;		//���������� ������ � �����.
	int startingVertix;		//����� ��������� �������.

	setlocale(LC_ALL, "RUS");

	//���� ����� ���������� ������ � ����� � ������� ���������.
	greetUser();
	getVerticesAmount(&verticesAmount);
	adjMatrix = allocateAdjMatrix(verticesAmount);
	fillAdjMatrix(adjMatrix, verticesAmount);
	getStartingVertix(&startingVertix);
	//����� �������, �������������� ����� ����� � �� �����.
	findCostsDijkstraAndPrint(adjMatrix, verticesAmount, startingVertix);
	//����������� ������.
	freeMatrix(adjMatrix, verticesAmount);
}

//�������, �������� ���������� � ��������� � �������������� ������������.
int greetUser() {
	printf("��� ����������� ��������� Graph_Dijkstra.\n\n"
		"��������� ������������� ��� ����������� ��������� ������:\n\n"
		"������������ ������ ��������������� ����, ������� ����� ������������� ��������� ����\n"
		"����� ���������. ��������� ����������� ��������� ���� �� �������� ������� �� ���\n"
		"���������. �������� ��������.\n"
		"�����: ���������� ������\n ������: ���-13��.\n\n");
}