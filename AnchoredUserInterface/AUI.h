#pragma once

#include <memory>
#include "Container.h"

namespace aui
{

	class AUI
	{
	
	private:

		// Root pointer of the interface
		Container root;

	public:

		// Constructor
		AUI();

		// Get a reference to the root
		Container* getRoot();
		Container* getRoot(double width, double height);

		// Get the node with specified name AT OR UNDER this node as a certain type
		template <typename T>
		T* find(std::string name)
		{
			Node* node = root.find(name);
			if (node == nullptr) return nullptr;
			return dynamic_cast<T*>(node);
		}

	};

}