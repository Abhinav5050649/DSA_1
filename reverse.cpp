#include "bits/stdc++.h"
using namespace std;

//Modifications required!!!!. Problem in the reversal part
typedef struct Node
{
	int key;
	Node* next = NULL;
}Node;

int main()
{
	Node *n = new Node;
	n->key = 1, n->next = NULL;

	Node* head = n, *temp = head;
	stack<Node*> ns;
	for (int i = 0; i < 5; i++)
	{
		Node *n = new Node;
		cout << "Enter a number: ";
		int num = 0; cin >> num;
		n->key = num, n->next = NULL;
		ns.push(n);
		temp->next = n;
		temp= temp->next; 
	}
	
	temp = head;
	//Printing linked List
	while (temp != NULL)
	{
		cout << "(" << temp->key << ") -->";
		temp=temp->next;
	}
	cout << endl;
	//Deleting linked list!
	
	n = head;
	while (n != NULL)
	{
		temp = n;
		n = n->next;
		delete temp;
	}	
	
	//Printing reversed linked list!
	Node* newlist = ns.top(), *newhead = newlist;
	ns.pop();
	newlist  = newlist ->next;
	for (int i = 0;i < 5; i++)
	{
		Node *n = new Node;
		n = ns.top();
		ns.pop();
		cout << n->key << endl;
		newlist = n;
		newlist = newlist->next;		
	}
	
	temp = newhead;
	//Printing linked List
	while (temp != NULL)
	{
		cout << "(" << temp->key << ") -->";
		temp=temp->next;
	}
	cout << endl;
	//Deleting linked list!
	
	n = newhead;
	while (n != NULL)
	{
		temp = n;
		n = n->next;
		delete temp;
	}	

	return 0;
}
