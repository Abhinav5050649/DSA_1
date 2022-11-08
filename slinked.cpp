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
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
    public:
    Node* head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node* n)
    {
        head = n;
    }

    //To check if node exists using key value
    Node* nodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }
        return temp;
    }

    //Append node to end of list

    void AppendNode(Node* n)
    {
        if (nodeExists(n->key) != NULL) //Checking if value in new node's key matches with another node's existing key value
        {
            cout << "Node Already exists with key value: " << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node* ptr = head;
                while (ptr-> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr->next = n;

                cout << "Node appended\n";
            }
        }
    }

    //Prepending node - Attach a node at the start
    void Prepend_Node(Node* n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key <<". Append another node with different key value.";
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended\n";
        }
    }

    //Insert a node after a particular node in the list
    void InsertNodeAfter(int k, Node* n)
    {
        Node* ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (nodeExists(n->key)!= NULL)
            {
                cout << "Node already exists with key value: " << n->key <<". Append another node with different key value.";
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;

                cout << "Node inserted!\n"; 
            }
        }
   }

   //Delete node with help of unique key
   void DeleteNodeByKey(int k)
   {
       if (head == NULL)
       {
           cout << "Singly Linked List already empty and so can't be deleted!\n";
       }
       else if (head != NULL)
       {
           if (head -> key == k)
           {
               head = head -> next;
               cout << "Node UNLINKED with keys value: " << k << endl;
           }
           else
           {
               Node* temp = NULL;
               Node* prevptr = head;
               Node* currentptr = head -> next;

               while(currentptr != NULL)
               {
                   if (currentptr->key == k)
                   {
                       temp = currentptr;
                       currentptr = NULL;
                   }
                   else
                   {
                       prevptr =  prevptr -> next;
                       currentptr = currentptr -> next;
                   }
               }

               if (temp != NULL)
               {
                   prevptr->next = temp -> next;
                   cout << "Node UNLIKNED with keys value: " << k << endl;
               }
               else
               {
                   cout << "Node with given key value " << k << " doesn't exist" << endl;
               }
           }
       }
   }
       //Update Node by key value
        void UpdateNodeByKeyValue(int k, int d)
        {
           Node *ptr = nodeExists(k);
           if (ptr != NULL)
           {
               ptr -> data = d;
               cout << "Node data updated successfully!\n";
           } 
           else
           {
               cout << "Node doesn't exist with the key value "<< k << endl;
           }
        }

       //Printing all elements of a linked List
        void printList()
        {
           if (head == NULL)
           {
               cout << "No nodes in singly linked list\n";
           }
           else
           {
               cout << endl << "Singly linked list values: ";
               Node* temp = head;

               while (temp != NULL)
               {
                   cout << "(" << temp -> key << "," << temp -> data << ") -->";
                   temp = temp -> next; 
               }
           }
        }
   
};

int main()
{
    SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. AppendNode()" << endl;
    cout << "2. Prepend_Node()" << endl;
    cout << "3. InsertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
        case 0:
            break;
        case 1:
                cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                s.AppendNode(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

    case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.Prepend_Node(n1);
      break;

    case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;

            s.InsertNodeAfter(k1, n1);
      break;

    case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.DeleteNodeByKey(k1);

      break;
    
    case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.UpdateNodeByKeyValue(key1, data1);

      break;
    
    case 6:
        s.printList();
        break;

    case 7:
      system("cls");
      break;
    
    default:
        cout << "Enter Proper Option number " << endl;
      break;
    }

  } while (option != 0);

    return 0;
}