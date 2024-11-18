#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>

using namespace std;


struct Node {
	int data;
	Node* next;
	Node* prev;
};


class Linkedlist {
private:
	Node* head = NULL;

public:
	bool isFound(int x);

	bool isEmpty();

	void add_beg(int x);

	void add_end(int x);

	void add_before(int item, int x);

	void delete_beg();

	void delete_end();

	void delete_at(int x);

	void add_after(int item, int x);

	void print();

	void reverselist();

	Node* getHead();
};

#endif // !LINKEDLIST.H

