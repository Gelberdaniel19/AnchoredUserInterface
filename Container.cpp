#include "Container.h"

namespace aui
{

	Node& Container::add(NodePtr p_node)
	{
		Node& node = *p_node;
		children.emplace_back(std::move(p_node));
		return node;
	}

	Node* Container::get(std::string name)
	{
		for (auto it = children.begin(); it < children.end(); it++)
		{
			if ((*it)->getName() == name)
			{
				return it->get();
			}
		}
	}

}