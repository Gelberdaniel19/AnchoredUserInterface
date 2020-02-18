#include "Container.h"

namespace aui
{

	Node* Container::add(std::unique_ptr<Node> p_node)
	{
		Node* res = p_node.get();
		children.emplace_back(std::move(p_node));
		return res;
	}

	// Find the child at or under this container
	Node* Container::find(std::string name)
	{
		if (this->name == name) return this;

		for (auto it = children.begin(); it < children.end(); it++)
		{
			Node* found = (*it)->find(name);
			if (found != nullptr)
			{
				return found;
			}
		}

		return nullptr;
	}

}