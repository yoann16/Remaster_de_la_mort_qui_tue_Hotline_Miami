#pragma once
#include "IComponent.h"

class IComposite : public IComponent
{
public:
	friend IComponent;
	IComposite(IComposite* parent);
	IComposite();
	~IComposite();
	void display() override;
protected:
	void AddChild(IComponent* child) ;
	void RemoveChild(IComponent* child) ;
	const std::vector<IComponent*>& getChildren() const;
	IComposite* GetParent() override;
	const IComposite* GetParent() const override;

private:
	std::vector<IComponent*> m_children;
};
