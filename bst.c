#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

//���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����

treeNode* searchBST(treeNode* root, element x)
{
	treeNode* p;
	p = root;
	while (p != NULL)
	{
		if (x < p->key) 
		{
			p = p->left;
		}
		else if (x = p->key)
		{
			return p;
		}

		else
		{
			p = p->right;
		}

	}

	printf("ã�� Ű�� �������� �ʽ��ϴ�. \n");
	return p;

}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
treeNode* insertBSTNode(treeNode* p, element x)
{
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode -> key = x;
		newNode -> left = NULL;
		newNode -> right = NULL;
		return newNode;
	}
	else if (x < p->key)
	{
		p->left = insertBSTNode(p->left, x);
	}

	else if (x > p->key)
	{
		p->right = insertBSTNode(p->right, x);
	}

	else
	{
		printf("\n �̹� ���� Ű�� �����մϴ�.");
	}

	return p;

}

// ��Ʈ ������ Ž���� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteBSTNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;

	treeNode* child;


	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) // ������ ����� ��ġ Ž��
	{
		parent = p;

		if (key < p->key)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	// ������ ��尡 ���� ���
	if (p == NULL)
	{
		printf("\n ã�� Ű�� ���� Ʈ���� �����!");
		return;
	}
	// ������ ��尡 �ܸ� ����� ��� (�޸� �ڽĳ�尡 �ϳ��� ����.)
	if ((p->left == NULL) && (p->right == NULL))
	{
		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}

		}
		else
		{
			root = NULL;
		}
	}

	// ������ ��尡 �ڽ� ��带 �ϳ� ���� ��� ( �޸� �ڽ� ��尡 �ϳ� )
	else if ((p->left == NULL) || (p->right == NULL))
	{
		if (p->left != NULL)
		{
			child = p->left;
		}

		else
		{
			child = p->right;
		}




		if (parent != NULL)
		{
			if (parent->left == p)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		
		}
		else
		{
			root = child;
		}

	}

	// ������ ��尡 �ڽ� ��带 �� �� ���� ���
	else
	{
		succ_parent = p;
		succ = p->left;

		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}

		if (succ_parent->left == succ)
		{
			succ_parent->left = succ->left;

		}
		else
		{
			succ_parent->right = succ->left;
		}

		p->key = succ->key;
		p = succ;
	}
	free(p);
}


