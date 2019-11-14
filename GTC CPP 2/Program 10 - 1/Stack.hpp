#pragma once
#include <vector>

template <class T>
class Stack
{
public:
	void push(T);
	void pop();
	T& top();
	unsigned int size();
	bool empty();
private:
	std::vector<T> m_data;
};

#include "Stack.tpp"