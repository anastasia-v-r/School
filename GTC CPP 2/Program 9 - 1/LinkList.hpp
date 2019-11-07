#pragma once
#include <string>

struct ListNode;

class LinkedList
{
public:
	// Constructor
	LinkedList() : head{ nullptr } {};
	// Destructor
	~LinkedList();
	// Processors
	void appendNode(std::string);
	void insertNode(std::string);
	void deleteNode(std::string);
	void displayList() const;
private:
	// Node Data
	struct ListNode
	{
		std::string data;
		struct ListNode* next;
	};
	// Data
	ListNode* head;
};