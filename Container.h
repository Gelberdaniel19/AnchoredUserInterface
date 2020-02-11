#pragma once

#include <vector>
#include <string>
#include "Node.h"

namespace aui
{

	using ContainerRef = Container&;

	class Container : public Node
	{
		friend class AUI;

		Component(Container)

	private:

		// For use by AUI to create the root
		Container() : Node() {}

	protected:

		std::vector<NodePtr> children;

	public:

		virtual Node& add(NodePtr p_node);
		Node* get(std::string name);

		template <typename T> 
		T* get(std::string name)
		{
			for (auto it = children.begin(); it < children.end(); it++)
			{
				if ((*it)->name == name)
				{
					return std::dynamic_pointer_cast<T*>(it->get());
				}
			}
		}
	
	};

}