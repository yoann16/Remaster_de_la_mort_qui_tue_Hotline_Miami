#pragma once

#include <iostream>
#include <vector>
#include <type_traits>

class IComposite;

class IComponent
{
public:
	virtual~IComponent();
	virtual void display() = 0;
	virtual IComposite* GetParent() = 0;
	virtual const IComposite* GetParent() const = 0;
	virtual void onBeforeParentChanged() {} //TODO changer ça dans le diagramme UML(POUR NPC,SCENE,MENU)
	virtual void onParentChanged() {}
	void setParent(IComposite* newParent);
protected:
	IComponent(IComposite* parent = nullptr);

protected:
	IComposite* m_parent;
};