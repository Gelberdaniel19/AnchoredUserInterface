#include "Node.h"
#include "Container.h"

namespace aui
{

	Node::Node(Container* parent)
		: parent(parent) { }

	Node* Node::create(Container* parent)
	{
		std::unique_ptr<Node> p_node = std::make_unique<Node>(parent);
		Node* node = parent->add(std::move(p_node));
		node->Init();
		return node;
	}

	void Node::Init() { }

	Node* Node::find(std::string name)
	{
		if (this->name == name) {
			return this;
		}
		return nullptr;
	}


	Container* Node::getParent()
	{
		return parent;
	}

	double Node::getX() const
	{
		return x;
	}

	double Node::getY() const
	{
		return y;
	}

	double Node::getWidth() const
	{
		return this->width;
	}

	double Node::getHeight() const
	{
		return this->height;
	}

	std::string Node::getName() const
	{
		return this->name;
	}

	Node* Node::setWidth(double width)
	{
		this->width = width;
		return this;
	}

	Node* Node::setHeight(double height)
	{
		this->height = height;
		return this;
	}

	Node* Node::setName(std::string name)
	{
		this->name = name;
		return this;
	}

}