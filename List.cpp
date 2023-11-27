#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//实现线性表的基本操作

//1.顺序表

typedef struct {
	int data[MAX_SIZE];
	int length;
}SeqList;

void initSeqList(SeqList* L) {
	L->data[0] = 1;
	L->data[1] = 2;
	L->data[2] = 3;
	L->data[3] = 4;
	L->data[4] = 5;
	L->length = 5;
}


void GetSeqList(SeqList L, int i, int* e) {
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
	printf("顺序表元素为：");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}


void deleteSeqListElem(SeqList* L, int i) {
	if (i > L->length || i < 1) return;
	for (int j = i; j <= L->length - 1; j++) {
		L->data[j - 1] = L->data[j];
	}
	L->length--;
}

void testList1() {
	SeqList mylist;
	initSeqList(&mylist);
	printf("初始态");
	showSeqList(mylist);


	printf("用值传递：");
	insertSeqList2(mylist, 3, 666);
	showSeqList(mylist);


	printf("用地址传递：");
	insertSeqList(&mylist, 3, 666);
	showSeqList(mylist);

	//获取第一个元素
	int e;
	GetSeqList(mylist, 1, &e);
	printf("获取到的第一个元素为:%d\n", e);


	//查找元素
	int location = LocateSeqList(mylist, 666);
	printf("666的位置在:%d", location);


	//删除元素
	printf("删除第二个元素后\n");
	deleteSeqListElem(&mylist, 2);
	showSeqList(mylist);
}




//链表的基本操作
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;


void creatLNode(LinkList &L, int n,int *data) {
	L = new LNode;
	L->next = NULL;
	LNode *r = L;
	for (int i = 0; i < n; i++) {
		LNode *p = new LNode;
		p->data = data[i];
		p->next = NULL;
		r->next = p;
		r = p;
	}
}


void GetLNodeElem(LinkList L, int i, int &e) {
	LNode* p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i)
		return;
	e = p->data;
}


void insertNode(LinkList &L, int i, int data) {
	LNode* p = L;
	int j = 1;
	while (p && j < i + 1) {
		p = p->next;
		j++;
	}
	LNode* newNode = new LNode;
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
}


void deleteNode(LinkList &L, int i) {
	LNode* p = L;
	int j = 1;
	while (p->next && j < i + 1)
	{
		p = p->next;
		j++;
	}
	LNode* q = p->next;
	p->next = q->next;
	delete q;
}

void displayNode(LNode* L) {
	LNode* p = L->next;
	while (p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

void testList2() {
	LinkList L = NULL;
	int initData[] = { 1,2,3 };
	creatLNode(L, 3, initData);
	displayNode(L);
	insertNode(L, 2, 10);
	printf("插入元素后：\n");
	displayNode(L);
	deleteNode(L, 1);
	printf("删除后：\n");
	displayNode(L);
}
