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
        Node* temp = NULL;
        Node* ptr = head;

        while (ptr != NULL)
        {
            if(ptr -> key == k)
            {
                temp = ptr;
            }

            ptr = ptr -> next;
        }

        return temp;
    }

    void AppendNode(Node* n)
    {
        Node* temp = NULL;

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node with given key value can't be appended to the list as a node with this key value already exists in the list!\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                
                cout << "Node appended!\n";
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = n;
                cout << "Node appended!\n";
            }
        }
    }

    void DeleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Node can't be deleted as list is empty!\n";
        }
        else
        {
            if (head -> key == k)
            {
                head = head -> next;
                cout << "Node unlinked successfully!\n";
            }
            else
            {
                Node* temp = NULL;
                Node* currentptr = head -> next;
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
                        prevptr = prevptr -> next;
                        currentptr = currentptr-> next;
                    }
                }
            }
        }
    }   

    void UpdateNode(int k, int d)
    {
        Node* ptr = nodeExists(k);

        if (ptr != NULL)
        {
            ptr -> data = d;
            cout << "Node updated successfully!\n";
        }
        else
        {
            cout << "No such node exists!\n";
        }
    }

    void InsertNodeAfter(int k, Node* n)
    {
        Node* ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "Node with given key value doesn't exist!\n";
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with this added node's key already exists in list!\n";
            }
            else
            {
                n->next = ptr->next;
                ptr ->next = n;
                cout << "Node inserted successfully!\n";
            }
        }
    }

    void PrependNode(Node* n)
    {
        if (head == NULL)
        {
            head = n;
            cout << "Node prepended successfully!\n";
        }
        else if (head != NULL)
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with key value " << n->key << " already exists in the list!\n";
            }
            else
            {
                n->next = head -> next;
                head = n;
                cout << "Node prepended successfully!\n";
            }
        }
    }  

    void Print_list()
    {   
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->key << " , " << temp->data << endl;
            temp = temp -> next;
        }
    }
};

int main()
{
    SLL s;
    int key1, k1, data1, option;
    
    do
    {
        cout << "Enter numbers between 1 to 7 to perform some operation related to linked lists. Press zero to exit!\n";
        cout << "1. AppendNode()\n";
        cout << "2. PrependNode()\n";
        cout << "3. InsertNodeAfter()\n";
        cout << "4. DeleteNodebyKey()\n";
        cout << "5. UpdateNode()\n";
        cout << "6. Print_List()\n";
        cout << "7. Clearscreen()\n";
        cin >> option;

        Node* n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter key and data to be appended!\n";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.AppendNode(n1);
            break;

        case 2:
            cout << "Enter key and data to prepend!\n";
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            s.PrependNode(n1);
            break;

        case 3:
            cout << "Enter key value of existing node after which you want to insert new node: ";
            cin >> k1;
            cout << "Enter key and data of new node: ";
            cin >> key1 >> data1;
            n1->data = data1;
            n1->key = key1;
            s.InsertNodeAfter(k1, n1);
            break;

        case 4:
            cout << "Enter key of node to be deleted: ";
            cin >> key1;
            s.DeleteNodeByKey(key1);
            break;

        case 5:
            cout << "Enter key of node to update: ";
            cin >> key1;
            cout << "Enter new data: ";
            cin >> data1;
            s.UpdateNode(key1, data1);
            break;
        
        case 6:
            s.Print_list();
            break;
        
        case 7:
            system("cls");
            break;

        default:
            break;
        }


    } while (option != 0);

    return 0;   
}