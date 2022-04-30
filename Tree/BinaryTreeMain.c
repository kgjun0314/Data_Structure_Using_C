#include <stdio.h>
#include "BinaryTree.c"

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	
	SetData(bt1, 1);	// bt1에 1 저장
	SetData(bt2, 2);	// bt2에 2 저장
	SetData(bt3, 3);	// bt3에 3 저장
	SetData(bt4, 4);	// bt4에 4 저장
	
	MakeLeftSubTree(bt1, bt2);		// bt2를 bt1의 왼쪽 자식 노드로
	MakeRightSubTree(bt1, bt3);		// bt3를 bt1의 오른쪽 자식 노드로
	MakeLeftSubTree(bt2, bt4);		// bt4를 bt2의 왼쪽 자식 노드로
	
	// bt1의 왼쪽 자식 노드의 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(bt1)));
	
	// bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
}