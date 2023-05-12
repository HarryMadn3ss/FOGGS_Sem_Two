#include "LinkedList.h"

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{
	
}

ListNode* LinkedList::MakeNode(ListNode** head, SceneObject* object)
{
	ListNode* newNode = new ListNode();
	ListNode* last = *head;

	newNode->object = object;
	newNode->next = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		return newNode;
	}
	while (last->next != nullptr)
	{
		last = last->next;
	}

	last->next = newNode;

	return newNode;
	
}

void LinkedList::DrawNode(ListNode* node)
{
	while (node != nullptr)
	{
		glPushMatrix();
		node->object->Draw();
		glPopMatrix();
		node = node->next;
	}
	
}

void LinkedList::UpdateNode(ListNode* node)
{
	while (node != nullptr)
	{
		node->object->Update();
		node = node->next;
	}
	
}

void LinkedList::DeleteList(ListNode** node)
{
	ListNode* pTemp = *node;
	ListNode* next;

	if (node != nullptr)
	{		
		next = pTemp->next;
		DeleteList(&next);		
		delete pTemp;
		
	}
	*node = nullptr;
}
