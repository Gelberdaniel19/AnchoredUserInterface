#pragma once

#include <vector>
#include <string>
#include "Node.h"

namespace aui
{

	class Container : public Node
	{
		friend class AUI;

		AUI_Component(Container, Node)

	private:

		// For use by AUI to create the root
		Container() : Node() {}

	protected:

		std::vector<std::unique_ptr<Node>> children;

	public:

		virtual Node* add(std::unique_ptr<Node> p_node);

		// Find the child at or under this container
		virtual Node* find(std::string name);
	
	};

}