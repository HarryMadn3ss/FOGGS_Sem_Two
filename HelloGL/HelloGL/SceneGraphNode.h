#pragma once
#include "SceneObject.h"

class SceneGraphNode
{
private:
	SceneGraphNode* _child = nullptr;
	SceneGraphNode* _sibling = nullptr;
	SceneObject* _data;

public:
	SceneGraphNode(SceneObject* data)
	{
		_data = data;
	}

	SceneGraphNode* AddChild(SceneGraphNode* child)
	{
		if (_child == nullptr)
		{
			_child = child;
		}
		else
		{
			_child->AddSibling(child);
		}

		return child;
	}

	void AddSibling(SceneGraphNode* sibling)
	{
		if (_sibling == nullptr)
		{
			_sibling = sibling;
		}
		else
		{
			_sibling = sibling;
		}
	}

	void Update(float deltaTime)
	{
		if (_data != nullptr)
		{
			_data->Update();
		}

		if (_child != nullptr)
		{
			_child->Update(deltaTime);
		}

		if (_sibling != nullptr)
		{
			_sibling->Update(deltaTime);
		}
	}

	void Draw()
	{
		glPushMatrix();

		if (_data != nullptr)
		{
			_data->Draw();
		}

		if (_child != nullptr)
		{
			_child->Draw();
		}

		glPopMatrix();

		if (_sibling != nullptr)
		{
			_sibling->Draw();
		}
	}
};