﻿#include <iostream>

using namespace std;
const int numOfTrees = 50;
int numOfNodes = 10000;

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* treeInsert(TreeNode* t, int data)
{
	TreeNode* newNode;
	newNode = new TreeNode;
	newNode->key = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	TreeNode* current = t;
	TreeNode* parent = t;
	if (t == nullptr)
	{
		t = newNode;
	}
	else
	{
		while (current->key != data)
		{
			parent = current;
			if (current->key > data)
			{
				current = current->left;
				if (current == nullptr)
				{
					parent->left = newNode;
					return t;
				}
			}
			else
			{
				current = current->right;
				if (current == nullptr)
				{
					parent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}

void printTree(TreeNode* root)
{
	if (root)
	{
		cout << root->key;
		if (root->left || root->right)
		{
			cout << '(';
			if (root->left)
			{
				printTree(root->left);
			}
			else
			{
				cout << "NULL";
			}
			cout << ',';
			if (root->right)
			{
				printTree(root->right);
			}
			else
			{
				cout << "NULL";
			}
			cout << ')';
		}
	}
}

int depth(TreeNode* root)
{
	if (root == nullptr)
	{
		return  0;
	}
	return 1 + ((depth(root->left) >= depth(root->right)) ? depth(root->left) : depth(root->right));
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
	{
		return  1;
	}
	int depthLeft = depth(root->left);
	int depthRight = depth(root->right);

	if (abs(depthLeft - depthRight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
	{
		return 1;
	}
	return 0;
}

bool binSearch(TreeNode* root, int value)
{
	if (root == nullptr)
	{
		return  false;
	}
	if (root->key == value)
	{
		return true;
	}
	if (value < root->key)
	{
		return binSearch(root->left, value);
	}
	if (value > root->key)
	{
		return binSearch(root->right, value);
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");

	//Задание 1
	TreeNode* trees[numOfTrees] = { nullptr };

	for (int k = 0; k < numOfTrees; k++)
	{
		for (int j = 0; j < numOfNodes; j++)
		{
			if (trees[k] == nullptr)
			{
				trees[k] = treeInsert(trees[k], rand());
			}
			else
			{
				treeInsert(trees[k], rand());
			}
		}
	}

	int balansed = 0;
	for (int k = 0; k < numOfTrees; k++)
	{
		if (isBalanced(trees[k]))
		{
			balansed++;
		}
	}
	balansed = balansed * 100 / numOfTrees;
	cout << "Деревья: \n\n";
	cout << "Cбалансировно: " << balansed << " %\n" << endl;

	//Задание 2
	cout << "Введите число для поиска: " << endl;
	int num;
	cin >> num;

	cout << "Поиск: " << num << endl;
	for (int k = 0; k < numOfTrees; k++)
	{
		(binSearch(trees[k], num)) ? cout << k << " - True" << endl : cout << k << " - False" << endl;
	}

	cout << endl;

	return 0;
}
