#include "bits/stdc++.h"
using namespace std;

typedef struct Node
{
    int data; 
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
}
Node;

typedef struct Queue
{
    Node *front = NULL, *rear = NULL;

    void Display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << "(" << temp ->data  << ")--> ";
            temp = temp -> next;
        }

        cout << "\n";
    }

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int count()
    {
        if (front == NULL && rear == NULL)
        {
            return 0;
        }
        else{
            Node *temp = front;
            int cnt = 0;
            while (temp != NULL)
            {
                cnt++;
                temp = temp -> next;
            }
            return cnt;
        }
    }

    void enqueue(Node* n)
    {
        if (front == NULL && rear == NULL)
        {
            front = n;
            rear = n;
        }
        else{
            rear -> next = n;
            rear = n;
        }

        cout << "Enqueue Successful!\n";
    }

    void Dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue Underflow\n";
            return;
        }
        else if (!(isEmpty()))
        {
            if (front == rear)
            {
                Node* temp = front;
                front = NULL, rear = NULL;
                delete temp;
            }
            else{
                Node *temp = front;
                front = front ->next;
                delete temp;
            }
            cout << "Dequeue successful!\n";
        }
    }

    void Delete()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            Node *ptr = temp;
            temp = temp->next;
            delete ptr;
        }

        cout << "Deletion Successful!\n";
    }   
}
Queue;

int main()
{
    int option = 0, da = 0;
    Queue q1;

    do
    {
        cout << "Enter appropriate option for a queue operation. Press 0 to exit.\n";
        cout << "1. Enqueue()\n";
        cout << "2. Dequeue()\n";
        cout << "3. Display()\n";
        cout << "4. Count()\n";
        cout << "5. isEmpty()\n";
        cout << "6. Clearscreen\n";

        cin >> option;

        Node *new_node = new Node();

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enter data to store in node: ";
                cin >> da;
                new_node->data =da;
                q1.enqueue(new_node);
                break;
            case 2:
                q1.Dequeue();
                break;
            case 3:
                q1.Display();
                break;
            case 4:
                cout << "Number of elements in stack: " << q1.count() << "\n";
                break;
            case 5:
                if (q1.isEmpty())
                {
                    cout << "Queue is Empty!\n";
                }
                else{
                    cout << "Queue is not empty!\n";
                }
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "Enter proper option number!\n";
                break;
        }
    } while (option != 0);
    
    q1.Delete();
    return 0;
}