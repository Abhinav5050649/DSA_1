#include "bits/stdc++.h"
using namespace std;

class Node
{
    public:
    int key, data;
    Node* next = NULL;

    Node()
    {
        key = 0, data= 0;
    }

    Node(int k, int d)
    {
        key = k, data = d;
    }
};

class CLL
{
    public:
    Node* head;

    CLL()
    {
        head = NULL;
    }  

    CLL(Node* n)
    {
        head = n;
    }

    Node* nodeExists(int k)
    {
        Node* temp = head, *ptr = NULL;
        if (head == NULL)
        {
            return ptr;
        }
        else
        {
            do
            {
                if (temp->key == k)
                {
                    ptr = temp;
                }

                temp = temp->next;
            } while (temp != head);

            return ptr;
        }   
    }

    void Append_Node(Node *n)
    {
        int k = n ->key;
        if (nodeExists(k) != NULL)
        {
            cout << "Please append unique node!\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node appended!\n";
            }
            else
            {
                Node* temp= head;

                while(temp->next != head)
                    temp = temp->next;

                temp->next = n;
                n->next = head;
                cout << "Node appended!\n";
            }
        }
    }

    void Prepend_Node(Node* n)
    {
        int k = n->key;
        if (nodeExists(k) != NULL)
        {
            cout << "Node with key value " << k << " already exists in the list!\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node prepended!\n";
            }
            else
            {
                Node* temp= head;
                while (temp->next != head)
                {
                    temp= temp->next;
                }

                temp->next = n;
                n->next = head;
                head = n;
                cout << "Node prepended!\n";
            }
        }
    }

    void InsertNodeAfter(int k, Node* n)
    {
        if (nodeExists(k) == NULL)
        {
            cout << "No node with key value " << k << " exists in the list!\n";
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Please insert noe with unique key value!\n";
            }
            else
            {
                Node *temp = head, *ptr = NULL;

                do
                {
                    if (temp->key == k)
                    {
                        ptr = temp;
                    }

                    temp = temp->next;
                } while (temp != head);
                 
                if (ptr->next == head)
                {
                    n->next = head;
                    ptr->next = n;
                    cout << "Node inserted!\n";
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted!\n";
                }
            }
        }
    }

    void DeleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "No such node exists in the list!\n";
        }
        else
        {
            if (ptr == head)
            {
                if (head ->next == NULL)
                {
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                    cout << "Head node deleted. List now empty!\n"; 
                }
                else
                {
                    Node *temp = head;
                    while (temp->next  != head)
                    {
                        temp = temp->next;
                    }

                    Node* temp1 = head;
                    temp->next = head->next;
                    head = head->next;
                    temp1->next = NULL;
                    delete temp1;
                    cout << "Head node deleted!\n";
                }
            }
            else
            {
                Node *temp = NULL, *prevptr = head, *currentptr = head->next;

                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr= prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                Node* temp1 = temp;
                prevptr->next = temp->next;
                temp1->next = NULL;
                delete temp1;
                cout << "Node deleted!\n";
            }
        }
    }

    void UpdateNode(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node updated!\n";
        }
        else
        {
            cout << "No node with given key found!\n";
        }
    }

    void Print_List()
    {
        if (head == NULL)
        {
            cout << "List is empty!\n";
        }
        else
        {
            Node *temp = head;
            cout << "Head address: " << head << endl << "Circular Linked List Values: " << endl;

            do
            {
                cout << "(" << temp->key << " , " << temp->data << " , " << temp << ") -->";
                temp = temp->next;
            } while (temp != head);
            cout << endl;

        }
    }
};

int main()
{
    int key1, data1, k, op;

    CLL c;

    do
    {
        
        cout << "Enter appropraite opition number. Press 0 to exit.\n";
        cout << "1. Append_Node()\n";
        cout << "2. Prepend_Node()\n";
        cout << "3. InsertNodeAfter()\n";
        cout << "4. UpdateNode()\n";
        cout << "5. DeleteNodeByKey()\n";
        cout << "6. Print_List()\n";
        cout << "7. Clearscreen()\n";

        cin >> op;
        Node* n1 = new Node();
        switch(op)
        {
            case 0:
                break;

            case 1:
                cout << "Enter key and data of node you wish to append: ";
                cin >> key1 >> data1;
                n1->key = key1, n1->data = data1;
                c.Append_Node(n1);
                break;

            case 2:
                cout << "Enter key and data of node you wish to append: ";
                cin >> key1 >> data1;
                n1->key = key1, n1->data = data1;
                c.Prepend_Node(n1);
                break;

            case 3:
                cout << "Enter key of node after which you wish to insert new node: ";
                cin >> k;
                cout << "Enter key and data of node you wish to append: ";
                cin >> key1 >> data1;
                n1->key = key1, n1->data = data1;
                c.InsertNodeAfter(k, n1);
                break;
            
            case 4:
                cout << "Enter key and new data for node to update: ";
                cin >> key1 >> data1;
                n1->data = data1, n1->key = key1;
                c.UpdateNode(key1, data1);
                break;

            case 5:
                cout << "Enter key of node you wish to delete from the list!\n";
                cin >> k;
                c.DeleteNodeByKey(k);
                break;

            case 6:
                c.Print_List();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Please enter proper option number!\n";
                break;
        }
        
    } while (op != 0);
    
    return 0;
}