#pragma once

#include <iostream>
#include <iomanip>
#include <memory>

#include "Structures.h"
#include "SceneObject.h"



class LinkedList
{
protected:

private:
	ListNode* head = nullptr;
	
	
public:
	
	LinkedList();
	~LinkedList();

	ListNode* MakeNode(ListNode** head, SceneObject* object);
	ListNode* InsertFirst(ListNode** head, SceneObject* object);
	ListNode* GetNode(ListNode* head, int pos);

	void DrawNode(ListNode* node);
	void UpdateNode(ListNode* node);

	void DeleteList(ListNode** node);
};

