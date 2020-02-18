#include <iostream>

#include "AUI.h"
#include "Component.h"  // Components are meant to be UI elements
#include "Block.h"      // Blocks are added functionality/data for components

using namespace aui;

// A block added to components which gives them
// an opacity
block OpacityBlock {
	AUI_Block;

public:
	int opacity{};

	Derived* setOpacity(int opacity) {
		this->opacity = opacity;
		return derived;
	}
};

// A block that adds color to a component
block ColorBlock{
	AUI_Block;

public:
	int r{};
	int g{};
	int b{};

	Derived* setColor(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
		return derived;
	}

	std::string colorAsStr() const {
		return std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b);
	}
};

// A rectangle is a node with an opacity and color
class Rectangle 
	: public Node, 
	  public OpacityBlock<Rectangle>,
	  public ColorBlock<Rectangle>
{
	AUI_Component(Rectangle, Node)

public:

	virtual void Init() {
		OpacityBlock::Init(this);
		ColorBlock::Init(this);
		width = 200;
		height = 100;
	}
};

int main()
{
    AUI gui;
    Container* root = gui.getRoot(1000, 1000);

    Container* box = Container::create(root)
        ->setName("box")
        ->setWidth(500)
        ->setHeight(500)
        ->as<Container>();

	Rectangle* rect = Rectangle::create(box)
		->setName("rect")
		->as<Rectangle>()
		->setOpacity(69)
		->setColor(255, 100, 0);

    std::cout << gui.find<Rectangle>("rect")->colorAsStr() << std::endl;
}