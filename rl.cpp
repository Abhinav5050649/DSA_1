#include "bits/stdc++.h"
using namespace std;

class Node
{
    public:
    int data;
    Node* next = NULL;

    Node()
    {
        data = 0;
    }
    Node(int d)
    {
        data =d;
    }
};

int main()
{
    Node* n = new Node;
    n->data = 1;
    //Creation of head node
    Node *head = n, *temp = head;

    //Looping the input process. Set the counter to loop as many times you want or for the desired length of list
    int list_length = 3;
    for (int i = 0; i < list_length; i++)
    {
        int num = 0; cout << "Enter number: "; cin >> num;
        Node *temp1 = new Node(num);
        temp->next = temp1;
        temp = temp ->next;
    }

    //Resetting temp pointer to traverse linked list for printing the list
    temp = head;
    while (temp != NULL)
    {
        cout << "(" << temp->data << ") --> ";
        temp = temp->next;
    }
    cout << endl;
    //Creating a vector of node pointers to and storing them in vectors
    vector<Node*> node_center;
    int cnt = 0;
    temp = head;

    while (temp != NULL)
    {
        cnt++;
        Node *ptr = temp;
        node_center.push_back(ptr);
        temp = temp->next;
    }

    //Defining method to reverse list using vector reverse
    reverse(node_center.begin(), node_center.end());

    //Defining new head and temp pointer for traversing reversed linked list
    Node *new_head = NULL, *new_ptr = NULL; 
    new_head = node_center[0];
    Node *new_temp = new_head;
    for (int i = 1; i < cnt; i++)
    {
        new_ptr = node_center[i];
        new_temp->next = new_ptr;
        new_temp= new_temp->next;
    }
    new_temp->next = NULL;  //Statement to ensure that head of old list(now at end of new list) 
    //doesn't start printing the old list during  the printing loop

    //Printing reversed linked list
    new_temp = new_head;
    while (new_temp != NULL)
    {
        cout << "(" << new_temp->data << ") -->";
        new_temp = new_temp->next;
    }
    cout << endl;

    //Deleting nodes of linked list
    for(int i= 1, p = list_length + 1; i <=p; i++)
    {
        Node *ptr = node_center[i - 1];
        delete ptr;
    }
    node_center.clear();

    //Checking proper deletion of all nodes of linked list
    cout << new_head->data << endl;
    return 0;
}