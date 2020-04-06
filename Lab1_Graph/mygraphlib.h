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
struct list {		//������, �������������� ����� ����� "�������".
	int curRank;	//����� �������� ����
	int curFile;	//����� ������� ������
	int curStep;	//����� ����
	int* path;		//������ ����� �����, ������������ ���� � ������� ������
	struct list * pNext;	//��������� �� ���������� ������� � �������
	struct list * pPrev;	//��������� �� ��������� ������� � �������
};
/*�������, ����������� ��������� ���� � �������. �������� ������, �������� ������.
!!�� �������� ������� ������!!*/
int getPosSteps(struct list * pQueue, struct list ** pQueueLast, int *** curField, int ranksAmount, int filesAmount);

//���������� �������, ����������� ����������� ���������� ���� � ����������� ��� � ������� � ������, ���� �� ��������.
int checkStep(struct list** pQueueLast, struct list* pQueueIn, int*** curField, int newRank, int newFile);

//�������, ��������� �������. pQueue - ����� ������� �������.
int clearQueue(struct list * pQueue);

//�������, ���������� ������ ��� ������� �������� �������
struct list * createFirstElem(int*** field, int initRank, int initFile);
#endif	//MYGRAPHLIB_H