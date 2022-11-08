#include "bits/stdc++.h"
using namespace std;

class Node
{
    public:
    int key, data;
    Node* next;

    Node()
    {
        key = 0, data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k, data = d;
        next = NULL; 
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

    Node* nodeExists(int k)
    {
        Node* temp = head;
        Node* ptr = NULL;
        while (temp != NULL)
        {
            if (temp->key != k)
            {
                ptr = temp;
            }
            temp = temp->next;
        }

        return temp;
    }

    void AppendNode(Node* n)
    {
    
        if (head == NULL)
        {
            head = n;
            cout << "Append successful!\n";
        }
        else        //Need to debug afterwards
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with key " << n->key << " can't be appended to the list!\n";
            }
            else
            {
                Node* temp = head;
                while (temp->next != NULL)
                {
                    temp = temp-> next;
                }

                temp->next = n;
                cout << "Append successful!\n";
            }
        }
    
    }

    void UpdateNode(int k, int d)
    {
        Node* temp = head;
        while (temp->key != k)
        {
            temp->next = temp;
        }

        temp->data = d;

        cout << "Updation successful!\n";
    }

    void InsertNode(int k, Node* n)
    {
        Node* temp = head;
        while (temp->key != k)
        {
            temp = temp-> next;
        }

        n->next = temp->next;
        temp-> next = n;
        cout << "Insetion successful!\n";
    }

    void PrependNode(Node* n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Prepend Operation Successful!\n";
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with key value " << n->key << " already exists in the list!\n";
            }
            else
            {
                n->next = head;
                head = n;
                cout << "Prepend operation successful!\n";
            }
        }
    }

    void DeleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Deletion is not possible as list is empty!\n";
        }
        else
        {
            if (head->key == k)
            {
                Node* temp = head;
                head = head-> next;
                delete temp;
                cout << "Deletion successful!\n";
            }
            else
            {
                Node* temp = NULL;
                Node* currentptr = head->next;
                Node* prevptr = head;

                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        currentptr=currentptr->next;
                        prevptr=prevptr->next;
                    }
                }

                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                    cout << "Deletion successful!\n";
                }
                else
                {
                    cout << "Node with key value " << k << " does not exist in list!\n";
                }
            }
        }
    }

    void Print_List()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << "(" << temp->key << "," << temp->data << ") --> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int key1, data1, option, k1;

    SLL s;

    do
    {
        cout << "Press numbers ffrom 1 to 7 to perform list operation. Press 0 to exit.\n";
        cout << "1. AppendNode()\n";
        cout << "2. PrependNode()\n";
        cout << "3. InsertNode()\n";
        cout << "4. UpdateNode()\n";
        cout << "5. DeleteNodeByKey()\n";
        cout << "6. Print_List()\n";
        cout << "7. Clearscreen()\n";
        cin >> option;
        Node* n1 = new Node();

        switch (option)
        {
            case 0:
                break;
            
            case 1:
                cout << "Enter key and data you wish to append to list: ";
                cin >> key1 >> data1;
                n1->key = key1;
                n1->data = data1;
                s.AppendNode(n1);
                break;

            case 2:
                cout << "Enter key and data you wish to prepend to list: ";
                cin >> key1 >> data1;
                n1->key = key1;
                n1->data = data1;
                s.PrependNode(n1);
                break;

            case 3:
                cout << "Enter key value of node after which you wish to insert new node: ";
                cin >> k1;
                cout << "Enter key and data you wish to insert into the list: ";
                cin >> key1 >> data1;
                n1->key = key1;
                n1->data = data1; 
                s.InsertNode(k1, n1);
                break;

            case 4:
                cout << "Enter key of node you wish to update: ";
                cin >> key1;
                cout << "Enter modified data: ";
                cin >> data1;
                s.UpdateNode(key1, data1);
                break;

            case 5:
                cout << "Enter key of node you wish to delete from list: ";
                cin >> key1;
                s.DeleteNodeByKey(key1);
                break;

            case 6:
                s.Print_List();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Please enter correct option number!\n";
                break;
        }

    } while (option != 0);
    
    return 0;
}