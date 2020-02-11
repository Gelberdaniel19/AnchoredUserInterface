#pragma once

#include <string>
#include <memory>

#pragma region Component Macro
#define Component(classname) using classname##Ptr = std::unique_ptr<classname>;\
private:\
	classname(Container& parent)\
		: Node(parent) { }\
public:\
	static classname##& create(Container& parent) {\
		classname##Ptr p_component = std::make_unique<classname>(parent);\
		classname##& component = *p_component;\
		parent.add(std::move(p_component));\
		component.Init();\
		return component;}
#pragma endregion

namespace aui
{
	class Container;
	class Node;
	using NodePtr = std::unique_ptr<Node>;
	using NodeRef = Node&;

	class Node
	{

	protected:
		friend class AUI;

		Container* parent = nullptr;
		std::string name = "";

		double x{}, y{};
		double width{}, height{};

		// For use by the container to create a node with no parent
		Node() {}

	public:

		Node(Container& parent);
		static Node& create(Container& parent);
		virtual void Init();

		Container* getParent();

		double getX() const;
		double getY() const;
		double getWidth() const;
		double getHeight() const;
		std::string getName() const;
		Node& setWidth(double width);
		Node& setHeight(double height);
		Node& setName(std::string name);
	
	};

}