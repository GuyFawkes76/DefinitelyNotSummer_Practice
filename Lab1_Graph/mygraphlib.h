//	��������� ����_���� (Graph_Horse)
//
//	������� ���� mygraphlib.h �������� ���������� ��������� � ������ ������� � ����� ������, ����������� ��� ������� ���� ������.
//
//	�����: ���������� ������
//	������: ���-13��
//

#ifndef MYGRAPHLIB_H
#define MYGRAPHLIB_H
#define HORSEFIRSTOFFSET 2		//���������� ������, ������� ���� ����� "�����".
#define HORSESECONDOFFSET 1		//���������� ������, ������� ���� ����� "� �������".
#define NEXTRANKOFFSET 1		//���������� ������, �� ������� ��������� ������ ��������� ��� ������������ �����������.
#define NOTVISITED 0			//���������, ������������ ������������ ������
#define VISITED 1				//���������, ������������ ���������� ��� ����������� ������
#define TARGET 2				//���������, ������������ ������� ������
struct queue {		//������, �������������� ����� ����� "�������".
	int curRank;	//����� �������� ����
	int curFile;	//����� ������� ������
	int curStep;	//����� ����
	int* path;		//������ ����� �����, ������������ ���� � ������� ������
	struct queue * pNext;	//��������� �� ���������� ������� � �������
	struct queue * pPrev;	//��������� �� ��������� ������� � �������
};

int getPosSteps(struct queue * pQueue, struct queue ** pQueueLast, int *** curField, int ranksAmount, int filesAmount);
int clearQueue(struct queue * pQueue);

#endif