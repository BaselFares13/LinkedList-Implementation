#include "Linkedlist.h"
#include<vector>
#include <iostream>

using namespace std;

bool Linkedlist::isFound(int x) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == x) {
			return 1;
		}

		temp = temp->next;
	}

	return 0;
}


bool Linkedlist::isEmpty() {
	return head == NULL;
}


void Linkedlist::add_beg(int x) {
	Node* newnode = new Node;
	newnode->data = x;
	newnode->next = head;
	head = newnode;
}


void Linkedlist::add_end(int x) {
	Node* newnode = new Node;
	newnode->data = x;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}


void Linkedlist::add_after(int item, int x) {
	if (isFound(item)) {
		Node* newnode = new Node;
		newnode->data = x;
		Node* cur = head;

		while (cur->data != item) {
			cur = cur->next;
		}

		newnode->next = cur->next;
		cur->next = newnode;
	}
	else {
		cout << "Item " << item << " isn't existing !!" << endl;
	}
}


void Linkedlist::add_before(int item, int x) {
	if (isFound(item)) {

		Node* newnode = new Node;
		newnode->data = x;
		Node* temp = head;

		if (head->data == item) {
			add_beg(x);
			return;
		}

		while (temp->next->data != item)
			temp = temp->next;

		newnode->next = temp->next;
		temp->next = newnode;
	}
	else {
		cout << "Item " << item << " is not exist !!" << endl;
	}
}


void Linkedlist::delete_beg() {
	if (isEmpty()) {
		cout << "Empty list !!" << endl;
	}
	else {
		Node* cur = head;
		head = head->next;
		delete cur;
	}
}


void Linkedlist::delete_end() {
	if (isEmpty()) {
		cout << "Empty list !!" << endl;
	}
	else if (head->next == NULL) {
		delete_beg();
	}
	else {
		Node* cur = head;
		Node* pre = NULL;

		while (cur->next != NULL) {
			pre = cur;
			cur = cur->next;
		}

		delete cur;
		pre->next = NULL;
	}
}


void Linkedlist::delete_at(int x) {
	
	if (!isFound(x)) {
		cout << "Item which you wanna delete, doesn't exist !!" << endl;
	}
	else if (head->data == x) {
		delete_beg();
	}
	else {
		Node* cur = head;
		Node* pre = NULL;

		while (cur->next != NULL && cur->data != x) {
			pre = cur;
			cur = cur->next;
		}

		pre->next = cur->next;
		delete cur;
	}
}


void Linkedlist::reverselist()
{
	Node* curr = head;
	Node* prev = NULL;
	Node* next = head->next;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}


void Linkedlist::print() {
	Node* temp = head;
	for (temp; temp != NULL; temp = temp->next)
	{
		cout << temp->data << endl;
	}
}

Node* Linkedlist::getHead()
{
	return head;
}