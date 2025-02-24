#include "IComposite.h"

IComposite::IComposite(IComposite* parent)
	: IComponent(parent)
{
}
IComposite::IComposite()
{
}
IComposite::~IComposite()
{
	std::cout << "Composite en cours de destuction, nettoyage de" << " " << m_children.size() << " " << "enfants" << std::endl;
	for (std::make_signed_t<size_t> idx = m_children.size()-1; idx>=0;--idx)
		delete m_children[idx];
	std::cout << "Composite détruit, enfant restant : "<< m_children.size()<< std::endl;
}
void IComposite::display()
{
	for (auto& child : m_children)
		child->display();
}
const std::vector<IComponent*>& IComposite::getChildren() const
{
	return m_children;
}
void IComposite::AddChild(IComponent* child)
{
	m_children.push_back(child);
}
void IComposite::RemoveChild(IComponent* child)
{
	auto it = std::find(m_children.begin(), m_children.end(), child);
	if (it == m_children.end())
		throw std::out_of_range("untraced child");
	m_children.erase(it);
}
IComposite* IComposite::GetParent() { return m_parent; }
const IComposite* IComposite::GetParent() const { return m_parent; }

