#pragma once
#include "IComponent.h"
class IComposite;
class ILeaf : public IComponent
{
public:
	ILeaf(IComposite* parent );
	void display() override;
	IComposite* GetParent() override;
	const IComposite* GetParent() const override;
};