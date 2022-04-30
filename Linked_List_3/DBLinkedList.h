#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE		1
#define FALSE		0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;		// 오른쪽 노드를 가리키는 포인터 변수
	struct _node * prev;		// 왼쪽 노드를 가리키는 포인터 변수
} Node;

typedef struct _DLinkedList
{
	Node * head;
	Node * cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);

#endif