#include "ILeaf.h"

ILeaf::ILeaf(IComposite* parent = nullptr)
	:IComponent(parent)
{
}
void ILeaf::display()
{
	std::cout << "child" << std::endl;
}
IComposite* ILeaf::GetParent() { return m_parent; }
const IComposite* ILeaf::GetParent() const { return m_parent; }