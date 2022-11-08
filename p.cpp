#include "bits/stdc++.h"
using namespace std;

typedef struct node
{
    int num;
    node* next;
}
node;

int main()
{
    node* temp = NULL;
    node* head = new node;
    head->num = 1;
    head ->next=NULL;

    temp = head;
    temp = temp->next;

    for (int i= 0; i < 3; i++)
    {
        node* n = new node;
        cout << "Enter number: ";
        int no = 0; cin >> no;
        n->num = no;
        temp = n;
        temp = temp ->next;
    }

    while (temp != NULL)
    {
        
    }
}