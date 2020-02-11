#include "AUI.h"
#include "Container.h"

namespace aui
{
	
	AUI::AUI() { }

	Container& AUI::getRoot()
	{
		return root;
	}

}