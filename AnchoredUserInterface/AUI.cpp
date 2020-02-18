#include "AUI.h"
#include "Container.h"

namespace aui
{
	
	AUI::AUI() 
	{ 
		root.setName("root");
	}

	Container* AUI::getRoot()
	{
		return &root;
	}

	Container* AUI::getRoot(double width, double height)
	{
		root.setWidth(width);
		root.setHeight(height);
		return &root;
	}

}