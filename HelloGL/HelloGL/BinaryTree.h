#pragma once

#include <iostream>
#include <iomanip>

#include "Structures.h"
#include "SceneObject.h"

class BinaryTree
{
protected:

private:

public:
	BinaryTree();
	~BinaryTree();

	TreeNode* MakeNode(TreeNode* node,SceneObject* object);

	void DeleteTree();
};

