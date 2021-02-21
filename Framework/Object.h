#pragma once

#include "Node.h"

class Object : public Node<Object>
{
public:
	void Init(void)
	{
		OnInit();
		Foreach([](std::shared_ptr<Object> child) {
			child->Init();
		});
	}
	void Update(void)
	{
		OnUpdate();
		Foreach([](std::shared_ptr<Object> child) {
			child->Update();
		});
	}
	void Draw(void)
	{
		OnDraw();
		Foreach([](std::shared_ptr<Object> child) {
			child->Draw();
		});
	}
	void Destroy(void)
	{
		OnDestroy();
		Foreach([](std::shared_ptr<Object> child) {
			child->Destroy();
		});
	}

protected:
	virtual void OnInit(void)
	{

	}
	virtual void OnUpdate(void)
	{

	}
	virtual void OnDraw(void)
	{

	}
	virtual void OnDestroy(void)
	{

	}
};
