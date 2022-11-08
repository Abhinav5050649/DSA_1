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

typedef struct Stack
{
    Node *front = NULL, *head = NULL;

    bool isEmpty()
    {
        if (head == NULL && front == NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int count()
    {
        if (head == NULL && front == NULL)
        {
            return 0;
        }
        else{
            Node *temp = head;
            int cnt = 1;
            
            do
            {
                cnt++;
                temp = temp->next;
            } while (temp != front);

            return cnt;    
        }
    }

    void Display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << "(" << temp->data << ") --> ";
            temp = temp->next;  
        }
        cout << "\n";
    }

    void Push(Node *n)
    {
        if (front == NULL && head == NULL)
        {
            head = n;
            front = n;
        }
        else if (head != NULL)
        {
            front ->next = n;
            front = n;
        }

        cout << "Node pushed into stack!\n";
    }

    void Pop()
    {
        if (head == NULL && front == NULL)
        {
            cout << "Stack Underflow!\n";
            return;
        }
        else if (front == head)
        {
            Node *temp = head;
            front = NULL, head = NULL;
            delete temp;
            return;
        }
        else{
            Node *temp = head;
            while (temp->next != front)
            {
                temp = temp->next;
            }

            Node *ptr = front;
            temp ->next = NULL;
            front = temp;

            delete ptr;
            return;
        }
    }

    void Top()
    {
        if (head == NULL && front == NULL)
        {
            cout << "Empty Stack!\n";
        }
        else{
            cout << "Top Details: " << front->data << "\n";
        }
    }

    void Delete()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            Node *ptr = temp;
            temp = temp ->next;
            delete ptr;
        }

        cout << "Deletion successful!\n";
    }
}
Stack;

int main()
{
    int option = 0, da = 0;
    Stack s1;

    do
    {
        cout << "Enter appropriate option for a stack operation. Press 0 to exit.\n";
        cout << "1. Push()\n";
        cout << "2. Pop()\n";
        cout << "3. Display()\n";
        cout << "4. Count()\n";
        cout << "5. isEmpty()\n";
        cout << "6. Top()\n";
        cout << "7.Clearscreen\n";

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
                s1.Push(new_node);
                break;
            case 2:
                s1.Pop();
                cout << "Node popped and deleted from stack!\n";
                break;
            case 3:
                s1.Display();
                break;
            case 4:
                cout << "Number of elements in stack: " << s1.count() << "\n";
                break;
            case 5:
                if (s1.isEmpty())
                {
                    cout << "Stack is Empty!\n";
                }
                else{
                    cout << "Stack is not empty!\n";
                }
                break;
            case 6:
                s1.Top();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter proper option number!\n";
                break;
        }
    } while (option != 0);
    
    s1.Delete();
    return 0;
}