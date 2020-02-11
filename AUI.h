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
		Container& getRoot();

	};

}