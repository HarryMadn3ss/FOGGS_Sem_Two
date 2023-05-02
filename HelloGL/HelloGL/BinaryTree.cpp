#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

TreeNode* BinaryTree::MakeNode(TreeNode* node,SceneObject* object)
{
	TreeNode* newNode = new TreeNode();

	newNode->object = object;
	newNode->Left = nullptr;
	newNode->right = nullptr;

	return newNode;

}

void BinaryTree::DeleteTree()
{
}
