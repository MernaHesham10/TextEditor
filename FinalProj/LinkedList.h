#pragma once
#include <fstream>
#include<stack>

template <class T>
class Node {

public:
	//for each node containing its value and a pointed to the next node
	Node<T>* next;
	T value;
	Node();
	Node(T val);
};

template <class T>
class LinkedList {
public:

	//Variables 
	int count; //No of Element In The List
	Node<T>* head;//the head pointer to a node
	Node<T>* tail;//the tail pointer to a node
	int numOfLines = 0;
	
	//Functions
	LinkedList();
	int Length();
	void AddAtTail(T);
	void InsertAt(int pos, T val);
	T GettextAt(int);
	void Update(int pos, T val);
	void FindAll(T text, int c);
	int FindLine(T firstText);
	//void find(T text, int);
	void DeleteAt(int pos);
	void Replace(T firstText, T secondText);
	void AppearanceCount(T, int);
	void Count(T, T);
	void Feedback(T feedback);
	void DisplayAll();
	void Exit();
	void clear();
	~LinkedList();
};