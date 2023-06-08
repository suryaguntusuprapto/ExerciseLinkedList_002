#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* suprapto;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nama;
	cout << "Enter roll number of the students: ";
	cin >> nim;
	cin.ignore();
	getline(cin, nama);
	Node* newNode = new Node();
	newNode->rollNumber = nim;
	newNode->name = nama;


	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->suprapto = newNode;
		newNode->suprapto = NULL;
		LAST = newNode;
		return;
	}

	Node* surya = LAST;
	while (surya->next != NULL && nim > surya->next->rollNumber)
		surya = surya->next;

	if (surya->next != NULL && nim == surya->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = surya->next;
	newNode->suprapto = surya;
	if (surya->next != NULL)
		surya->next->suprapto = newNode;
	surya->next = newNode;
}
bool CircularLinkedList::search(int rollno, Node** suprapto, Node** surya) {
	*suprapto = LAST->next;
	*surya = LAST->next;
	while (*surya != LAST) {
		if (rollno == (*suprapto)->rollNumber) {
			return true;
		}
		*suprapto = *suprapto;
		*surya = (*surya)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	if (listEmpty()) {
		cout << "\nList Is Empty" << endl;
		return false;
	}
	else {
		Node* surya = LAST->next;
		Node* suprapto = LAST->next->next;

		if (surya == LAST) {
			LAST = NULL;
			delete surya;
			return true;
		}
		LAST->next = suprapto;
		delete surya;
		return true;
	}

}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* suryaNode = LAST->next;
		while (suryaNode != LAST) {
			cout << suryaNode->rollNumber << " " << suryaNode->name << endl;
			suryaNode = suryaNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}