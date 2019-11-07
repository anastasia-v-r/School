#include "LinkList.hpp"
#include <iostream>
#include <string>

void LinkedList::appendNode(std::string str) {
	if (str.empty()) {
		throw std::invalid_argument("String must not be empty");
	} else if (str.length() > 100) {
		throw std::invalid_argument("String must be shorter than 100 characters");
	}
	ListNode* newNode; 
	ListNode* nodePtr; 
	
	newNode = new ListNode;
	newNode->data = str;
	newNode->next = nullptr;
	
	if (!head) {
		head = newNode;
	} else {
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void LinkedList::insertNode(std::string str) {
	if (str.empty()) {
		throw std::invalid_argument("String must not be empty");
	} else if (str.length() > 100) {
		throw std::invalid_argument("String must be shorter than 100 characters");
	}
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->data = str;

	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	} else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->data < str) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nullptr;
		} else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void LinkedList::deleteNode(std::string str) {
	ListNode *nodePtr;     
	ListNode *previousNode;
	
	if (!head) {
		return;
	}

	if (head->data == str) {
	    nodePtr = head->next;
	    delete head;
	    head = nodePtr;
	} else {
	    nodePtr = head;

	    while (nodePtr != nullptr && nodePtr->data != str) {
	        previousNode = nodePtr;
	        nodePtr = nodePtr->next;
	    }

	    if (nodePtr) {
	        previousNode->next = nodePtr->next;
	        delete nodePtr;
	    } else {
			throw std::invalid_argument("This element does not exist!");
		}
	}
}

void LinkedList::displayList() const {
	ListNode* nodePtr;

	nodePtr = head;
	while (nodePtr) {
		std::cout << nodePtr->data << std::endl;
		nodePtr = nodePtr->next;
	}
}

LinkedList::~LinkedList()
{
    ListNode *nodePtr;   
    ListNode *nextNode;  
    nodePtr = head;

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}