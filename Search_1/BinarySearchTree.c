#include <stdio.h>
#include "BinaryTree2.c"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;		// parent node;
	BTreeNode * cNode = *pRoot;		// current node;
	BTreeNode * nNode = NULL;		// new node;
	
	// 새로운 노드가 추가될 위치를 찾는다.
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;
		
		pNode = cNode;
		
		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	// 새 노드의 생성
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	
	if(pNode != NULL)
	{
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;		// current node
	BSTData cd;						// current data
	
	while(cNode != NULL)
	{
		cd = GetData(cNode);
		
		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	return NULL;
}