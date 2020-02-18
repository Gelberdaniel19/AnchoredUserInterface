#pragma once

#include <string>
#include <memory>

#pragma region Component Macro
#define AUI_Component(classname, parentname) using classname##Ptr = std::unique_ptr<classname>;\
public:\
	classname(aui::Container* parent)\
		: parentname##(parent) { }\
	static classname##* create(aui::Container* parent) {\
		classname##Ptr p_component = std::make_unique<classname>(parent);\
		classname##* rp_component = p_component.get();\
		parent->add(std::move(p_component));\
		rp_component->Init();\
		return rp_component;}\
private:
#pragma endregion

namespace aui
{
	class Container;

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

		Node(Container* parent);

		static Node* create(Container* parent);
		virtual void Init();

		template <typename T>
		T* as()
		{
			return dynamic_cast<T*>(this);
		}

		// Get the node with specified name AT OR UNDER this node
		virtual Node* find(std::string name);

		Container* getParent();

		double getX() const;
		double getY() const;
		double getWidth() const;
		double getHeight() const;
		std::string getName() const;
		Node* setWidth(double width);
		Node* setHeight(double height);
		Node* setName(std::string name);
	
	};

}