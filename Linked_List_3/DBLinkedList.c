#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head;		// 새 노드가 기존 노드를 가리키게 한다.
	if(plist->head != NULL)		// 두 번째 이후의 노드를 추가할 때만 실행
		plist->head->prev = newNode;		// 기존 노드가 새 노드를 가리키게 한다.
	
	newNode->prev = NULL;		// 새 노드의 prev를 NULL로 초기화
	plist->head = newNode;		// 포인터 변수 head가 새 노드를 가리키게 함
	
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)		// 첫 번째 노드의 데이터 조회
{
	if(plist->head == NULL)
		return FALSE;
	
	plist->cur = plist->head;		// cur이 첫 번재 노드를 가리키게 함
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LNext(List * plist, Data * pdata)		// 두 번째 이후의 노드 데이터 조회
{
	if(plist->cur->next == NULL)
		return FALSE;
	
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LPrevious(List * plist, Data * pdata)		// LNext의 반대 방향으로 데이터 조회
{
	if(plist->cur->prev == NULL)
		return FALSE;
	
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}