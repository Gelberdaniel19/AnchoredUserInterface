#pragma once

#define block template <class Derived> class

#define AUI_Block private:\
Derived* derived = nullptr;\
public:\
	void Init(Derived* derived){\
		this->derived = derived;\
	}\
private: