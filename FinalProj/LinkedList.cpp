#include "LinkedList.h"
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

struct txtSt {
	int lineNumber;
	string txt;
};

//Constructor Fn for Node Class
template <class T>
Node<T>::Node() {
	value = 0;
	next = 0;
}

//Parameterized Constructor Fn for Node Class
template <class T>
Node<T>::Node(T val) {
	value = val;
	next = 0;
}

//Constructor Fn for LinkedList Class
template <class T>
LinkedList<T>::LinkedList() {
	head = tail = 0;
	count = 0;
	
}

//Display Length of List
template <class T>
int LinkedList<T>::Length() {

	return count;
}

// AddAtTail Fn to Add Text At the End.
template <class T>
void LinkedList<T>::AddAtTail(T val) {

	Node<T>* newNode = new Node<T>(val);

	if (count == 0) {  //In case the list is empty
		head = tail = newNode;
		numOfLines++;
	}
	else {
		tail->next = newNode;
		tail = newNode;
		numOfLines++;
	}
	count++;
}

//InsertAt Fn to Add Text At Specific Position
template <class T>
void LinkedList<T>::InsertAt(int pos, T val) {
	// check that the position exists
	assert(pos >= 0 && pos < count); 
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);

	//if you want to insert at the first position 
	if (pos == 0) {  
		newNode->next = head;
		head = newNode;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

//GetIn Fn
template <class T>
T LinkedList<T>::GettextAt(int pos) {
	assert(pos >= 0 && pos < count); //validate input: check that the position exists
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

//Update Fn to modify Text at Specific Position
template<class T>
void LinkedList<T>::Update(int pos, T val) {

	assert(pos >= 0 && pos < count);
	Node<T>* temp = head;
	if (head == NULL) {
		cout << "\nThere's No Data!\n";
	}
	else {
		if (pos == 0) {
			temp->value = val;
		}
		else {
			for (int i = 0; i < pos; i++) {

				temp = temp->next;
			}
		}
		temp->value = val;
	}
}

//FindAll Fn
template<class T>
void LinkedList<T>::FindAll(T text, int c) {
	Node<T>* temp = head;
	int LineNumber = 0, check = 0;

	if (head == NULL) {
		cout << "\nThere's No Data!\n";
	}
	else {
		while (temp != NULL) {

			//If element is present in the list
			if (temp->value == text) {  
				cout << "Text Found At Line: " << (LineNumber + 1) << endl;
				//check = 0;
			}
			else {
				//check++;
			}
			LineNumber++;
			temp = temp->next;
		}
		/*If element is not present in the list
		if (check == c) { 
			cout << "Text Not Found\n";
		}*/
	}
}

//FindLine Fn
template<class T>
int LinkedList<T>::FindLine(T fisrtText) {
	Node<T>* temp = head;
	int LineNumber = 0;

	if (head == NULL) {
		cout << "\nThere's No Data!\n";
	}
	else {
		while (temp != NULL) {

			//If Element Is Present In The List
			if (temp->value == fisrtText) {
				LineNumber += 1;
			}
			LineNumber++;
			temp = temp->next;
		}
	}
	return LineNumber - 2;
}

/*template<class T>
void LinkedList<T>::find(T text, int numOfLines) {
	Node<T>* temp = head;
	int LineNumber = 0;
	int found, counter = 0, i = 0;
	string str, word;
	
	if (head == NULL) {
		cout << "\nThere's No Data!\n";
	}
	else {
		while (temp != NULL) {
			for (int i = 0; i < numOfLines; i++) {
				
				//If Element Is Present In The List
				
					found = temp->value.find(text, i);
					i = found + 1;
					if (found != -1) {
						LineNumber = i;
						++counter;
					}
					cout << "LineNumber = " << LineNumber << endl;

			}
				//LineNumber++;
				temp = temp->next;
		} 
	}
}*/

//Delete Fn
template<class T>
void LinkedList<T>::DeleteAt(int pos){

	stack<txtSt> textStack;
	if (head == NULL){
		cout << "There Is No Text to be Deleted." << endl;
	}
	else if (head == tail) {
		Node<T>* temp = head;
		delete(temp);
		head = NULL;
		tail = NULL;
		numOfLines--;
	}
	else if (pos == 1 || pos == 0) {
		string backup = head->value;
		Node<T>* temp = head;
		Node<T>* nextNode = head->next;
		head = nextNode;
		delete(temp);
		numOfLines--;
		txtSt headRemoved;
		headRemoved.txt = backup;
		headRemoved.lineNumber = 1;
		textStack.push(headRemoved);
	}
	else if (pos == numOfLines) {
		Node<T>* temp = head;
		txtSt deletedLine;
		
		while (temp->next != NULL && temp->next->next != NULL)
		{
			temp = temp->next;
		}
		tail = temp;
		string backup = temp->next->value;
		delete temp->next;
		temp->next = NULL;
		numOfLines--;
		deletedLine.txt = backup;
		deletedLine.lineNumber = pos;
		textStack.push(deletedLine);

	}
	else if (pos > numOfLines){
		cout << "Please! check your Line Entered." << endl;
	}
	else if (pos < numOfLines){
		txtSt deletedLine;
		Node<T>* prevNode = head;
		Node<T>* nextNode = head;
		Node<T>* temp = head;
		int iterator = 2;
		while (iterator < pos)
		{
			prevNode = prevNode->next;
			nextNode = nextNode->next;
			iterator++;
		}
		nextNode = nextNode->next;
		temp = nextNode;
		nextNode = nextNode->next;
		prevNode->next = nextNode;
		string backup = temp->value;
		delete(temp);
		numOfLines--;
		deletedLine.txt = backup;
		deletedLine.lineNumber = pos;
		textStack.push(deletedLine);
	}
}

//Replace Fn
template<class T>
void LinkedList<T>::Replace(T firstText, T secondText){
	int lineNumber = FindLine(firstText);
	stack<txtSt> textStack;
	txtSt replacedLine;
	if (numOfLines < lineNumber){
		cout << "Please! Check Entered Line Number." << endl;
	}
	else if (numOfLines >= lineNumber){
		Node<T>* tmp = head;
		int goToLine = 1;
		while (goToLine < lineNumber){
			tmp = tmp->next;
			goToLine++;
		}
		string backup = tmp->value;
		tmp->value = secondText;
		replacedLine.lineNumber = lineNumber;
		replacedLine.txt = backup;
		textStack.push(replacedLine);
	}
}


//AppearanceCount Fn to count the No oF Appearance a word in Text
template<class T>
void LinkedList<T>::AppearanceCount(T inputWord, int inputLine) {
	Node<T>* temp = head;
	int LineNumber = 0;
	string text;

	if (head == NULL) {
		cout << "\nThere's No Data!\n";
	}
	else {
		while (temp != NULL) {
			if (inputLine == LineNumber) {
				text = temp->value;
				Count(text, inputWord);
			}
			LineNumber++;
			temp = temp->next;
		}
	}
	//char* c = const_cast<char*>(g.c_str());
}

//Count Fn
template<class T>
void LinkedList<T>::Count(T inputStr, T inputWord) {

	int found, counter = 0, i = 0;
	string str = inputStr, word = inputWord;

	while (1) {
		found = str.find(word, i);
		i = found + 1;
		if (found != -1)
			++counter;
		else break;
	}
	cout << "No OF Appearance = " << counter << endl;
}

//Feedback Fn
template <class T>
void LinkedList<T>::Feedback(T feedback) {

	cout << "****Hello Dear User****" << endl;
	cout << "This App Help You to \n1. Add Text." << endl;
	cout << "2. Insert Text \n3. Get Text." << endl;
	cout << "4. Delete Text.\n5. Update Line.\n6. Find Line." << endl;
	cout << "7. Replace First Text with Second Text.\n8. The No of Times a Word W Appears in The Line N." << endl;
	cout << "\nPlease! Enter Your Feedback About This App." << endl;
	cin.ignore();
	getline(cin, feedback);
	cout << "****Thank You, Dear User****\n" << endl;
}

//DisplayAll Fn used to print the whole linked list
template<class T>
void LinkedList<T>::DisplayAll() { 
	
	Node<T>* temp = head;
	int lineNumber = 1;

	if (head == NULL){
		cout << "There's No Data to Display!" << endl;
	}
	else {
		while (temp != NULL){
			cout <<" ["<< lineNumber << "] " << temp->value << endl;
			temp = temp->next;
			lineNumber++;
		}
	}
}

//clear Fn
template <class T>
void LinkedList<T>::clear() {
	if (count == 0)
		return;
	Node<T>* tmp = head->next;
	while (tmp->next != 0) {
		delete head;
		head = tmp;
		tmp = tmp->next;
	}

	delete head;
	head = tail = 0;
	count = 0;
}

// Exit Fn
template<class T>
void LinkedList<T>::Exit() {
	exit(EXIT_SUCCESS);
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList(void) {
	clear();
}
