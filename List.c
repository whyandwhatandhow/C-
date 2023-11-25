#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//ʵ�����Ա�Ļ�������

//1.˳���

typedef struct {
	int data[MAX_SIZE];
	int length;
}SeqList;

void initSeqList(SeqList *L) {
	L->data[0] = 1;
	L->data[1] = 2;
	L->data[2] = 3;
	L->data[3] = 4;
	L->data[4] = 5;
	L->length = 5;
}


void GetSeqList(SeqList L, int i, int *e) {
	if (i<1 || i>L.length)
		return;
	*e = L.data[i - 1];
}


int LocateSeqList(SeqList L, int elem) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == elem) {
			return i + 1;
		}
	}
	return 0;
}


void insertSeqList(SeqList* L, int i, int elem) {
	if (i<1 || i>L->length) return;
	if (L->length == MAX_SIZE) return;
	for (int j = L->length - 1; j >= i - 1; j--) {
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = elem;
	L->length++;
}


void insertSeqList2(SeqList L, int i, int elem) {
	if (i<1 || i>L.length) return;
	if (L.length == MAX_SIZE) return;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.data[j + 1] = L.data[j];
	}
	L.data[i - 1] = elem;
	L.length++;
}

void showSeqList(SeqList L) {
	printf("˳���Ԫ��Ϊ��");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}


void deleteSeqListElem(SeqList* L, int i) {
	if (i > L->length || i < 1) return;
	for (int j = i; j <= L->length-1; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
}

void testList1() {
	SeqList mylist;
	initSeqList(&mylist);
	printf("��ʼ̬");
	showSeqList(mylist);


	printf("��ֵ���ݣ�");
	insertSeqList2(mylist, 3, 666);
	showSeqList(mylist);


	printf("�õ�ַ���ݣ�");
	insertSeqList(&mylist, 3, 666);
	showSeqList(mylist);

	//��ȡ��һ��Ԫ��
	int e;
	GetSeqList(mylist, 1, &e);
	printf("��ȡ���ĵ�һ��Ԫ��Ϊ:%d\n", e);


	//����Ԫ��
	int location=LocateSeqList(mylist, 666);
	printf("666��λ����:%d", location);


	//ɾ��Ԫ��
	printf("ɾ���ڶ���Ԫ�غ�\n");
	deleteSeqListElem(&mylist, 2);
	showSeqList(mylist);
}