#pragma once
#include "Stack.hpp"
#include <stdexcept>

template <class T>
void Stack<T>::push(T data) {
	m_data.push_back(data);
}

template <class T>
void Stack<T>::pop() {
	if (m_data.empty()) {
		throw std::logic_error("You tried to pop an empty stack");
	}
	m_data.pop_back();
}

template <class T>
T& Stack<T>::top() {
	if (m_data.empty()) {
		throw std::length_error("You tried to access an empty stack");
	}
	return m_data[m_data.size() - 1];
}

template <class T>
bool Stack<T>::empty() {
	return  m_data.empty();
}

template <class T>
unsigned int Stack<T>::size() {
	return m_data.size();
}