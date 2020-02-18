#pragma once

#include <unordered_map>

template <typename T>
class Manager {

	std::unordered_map<std::string, T> map;

public:

	// Gets the resource given by the key. If the key doesn't exist, this
	// function creates the resource.
	T& operator[] (std::string key) 
	{
		return map[name];
	}

	// Erases the resource given by the key. If the resource is not fount, do
	// nothing.
	void erase(std::string key)
	{
		auto it;
		if ((it = map.find(key)) != map.end())
		{
			map.erase(it);
		}
	}

	// Clears all the resouces
	void clear()
	{
		map.clear();
	}

	// Returns true if the resource given by the key exists
	bool exists(std::string key)
	{
		return map.find(key) != map.end();
	}

};