#include <stdio.h>
#include "BinaryTree3.c"
#include "BinarySearchTree2.h"

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

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	BTreeNode * pVRoot = MakeBTreeNode();	// 가상 루트 노드
	BTreeNode * pNode = pVRoot;				// parent node
	BTreeNode * cNode = *pRoot;				// current node
	BTreeNode * dNode;
	
	ChangeRightSubTree(pVRoot, *pRoot);
	
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;
		
		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	if(cNode == NULL)
		return NULL;
	
	dNode = cNode;
	
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;
		
		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);
		
		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;
		
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		
		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		
		dNode = mNode;
		SetData(dNode, delData);
	}
	
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);
	
	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}