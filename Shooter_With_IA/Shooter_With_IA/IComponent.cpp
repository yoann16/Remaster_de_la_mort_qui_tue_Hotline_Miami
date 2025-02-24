#include "IComponent.h"
#include "IComposite.h"
IComponent::IComponent(IComposite* parent)
	:m_parent(nullptr)
{
	setParent(parent);
}
IComponent::~IComponent()
{
	setParent(nullptr);
	std::cout << "Composant détruit, détaché de son parent" << std::endl;
}

void IComponent::setParent(IComposite* newParent)
{
	
	if (m_parent)
		m_parent->RemoveChild(this);

	auto* ancestor = newParent;
	while (ancestor != nullptr)
	{
		if (this == ancestor)
			throw std::logic_error("Attempt to create a cycle in the object hierarchy");
		ancestor = ancestor->m_parent;
	}

	m_parent = newParent;

	if (m_parent)
		m_parent->AddChild(this);
}