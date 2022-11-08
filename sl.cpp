#include "bits/stdc++.h"
using namespace std;

class Node
{
    public:
    int key, data;
    Node* next = NULL;

    Node()
    {
        key = 0, data = 0;
    }

    Node(int k, int d)
    {
        key = k, data = d;
    }
};

class SLL
{
    public:
    Node* head;

    SLL()
    {
        head = NULL;
    }
    
    SLL(Node* n)
    {
        head = n;
    }

    void Print_list()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << "(" << temp->key << "," << temp->data << ") --> ";
            temp = temp->next;
        }

        cout << endl;
    }

    Node* nodeExists(int k)
    {
        Node* ptr = NULL;
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->key == k)
            {
                ptr = temp;
            }
            temp = temp->next;
        }

        return ptr;
    }

    void AppendNode(Node* n)
    {
        Node* temp = head;

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node with key value " << n->key << " already exists in list!\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Append operation successful!\n";
            }
            else
            {
                while (temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp->next = n;
                cout << "Append operation successful!\n";
            }
        }
    }

    void InsertNodeAfter(Node* n, int k)
    {
        Node* temp = head;
        if (nodeExists(k) == NULL)
        {
            cout << "No node with given key value: " << k << " exists in the list!\n";
        }
        else
        {
               
                while (temp->key != k)
                {
                    temp = temp -> next;
                }

                n->next = temp ->next;
                temp -> next = n;
                cout << "Insertion successful!\n";
            
        }
        
    }

    void Prepend_Node(Node* n)
    {

        if (head == NULL)
        {
            head = n;
            cout << "Prepend operation successful!\n";
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with key value " << n->key << " exists in list!\n";
            }
            else
            {
                n->next = head;
                head = n;
                cout << "Prepend operation successful!\n";
            }
        }
    }

    void UpdateNodeByKey(int k, int d)
    {
        if (nodeExists(k) == NULL)
        {
            cout << "No node with key value " << k << " exists in the list!\n";
        }
        else
        {
            Node* temp = head;
            while (temp->key != k)
            {
                temp = temp -> next;
            }

            temp->data = d;
            cout << "Node updated successfully!\n";
        }
    }   

    void DeleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "List is empty!\nDeletion can't be performed!\n";
        }
        else
        {
            if (nodeExists(k) == NULL)
            {
                cout << "No node with given key " << k << " exists in list!\n";
            }
            else if (head -> key == k)
            {
                Node* temp = head;
                head = head -> next;
                delete temp;
                cout << "Deletion successful!\n";
            }
            else
            {
                Node* temp = NULL;
                Node* currentptr = head->next;
                Node* prevptr = head;

                while (temp == NULL)
                {   
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        currentptr = currentptr->next;
                        prevptr = prevptr->next;
                    }
                }

                if (temp != NULL)
                {
                    prevptr -> next = temp ->next;
                    temp -> next = NULL;
                    delete temp;
                    cout << "Deletion Successful!\n";
                }
                else
                {
                    cout << "No such node found in list!\n";
                }
            }
        }
    }

};

int main()
{
    int key1, data1, k1, option;

    SLL s;

    do
    {
        cout << "Press from 1 to 7 for an operation. Press 0 to exit\n";
        cout << "1. AppendNode()\n";
        cout << "2. Prepend_Node()\n";
        cout << "3. InsertNodeAfter()\n";
        cout << "4. UpdateNodeByKey()\n";
        cout << "5. DeleteNodeByKey()\n";
        cout << "6. Print_list()\n";
        cout << "7. Clearscreen()\n";

        cin >> option;
        Node* n1 = new Node();
        switch (option)
        {
            case 0:
                break;
        
            case 1:
                cout << "Enter key and data that you wish to append\n";
                cin >> key1 >> data1;
                n1->key = key1, n1->data = data1;
                s.AppendNode(n1);
                break;
            
            case 2:
                cout << "Enter key and data that you wish to prepend\n";
                cin >> key1 >> data1;
                n1->data = data1, n1->key = key1;
                s.Prepend_Node(n1);
                break;
            
            case 3:
                cout << "Enter key of node after which you wish to insert new node: ";
                cin >> k1;
                cout << "Enter key and data of node you wish to insert in list: ";
                cin >> key1 >> data1;
                n1->key = key1, n1->data = data1;
                s.InsertNodeAfter(n1, k1);
                break;
            
            case 4:
                cout << "Enter key of node you wish to update: ";
                cin >> key1;
                cout << "Enter new data: ";
                cin >> data1;
                s.UpdateNodeByKey(key1, data1);
                break;
            
            case 5:
                cout << "Enter key of node you wish to delete: ";
                cin >> k1;
                s.DeleteNodeByKey(k1);
                break;
            
            case 6:
                s.Print_list();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Enter proper option number!\n";
                break;
        }
    }
    while(option != 0);

    return 0;
}