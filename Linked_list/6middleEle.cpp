#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *create(Node *head)
{
    Node *new_node = new Node();
    cout << "Enter the data : ";
    cin >> new_node->data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = new_node;
    }

    return head;
}

void display(Node *head)
{
    Node *p = head;

    cout << "The elements are as follows : \n";

    while (p != NULL)
    {

        cout << p->data << endl;
        p = p->next;
    }
}

int Middle(Node *head)
{
    Node *p = head;
    Node *q = head;
    while (q)
    {
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
            p = p->next;
        }
        else
        {
            return p->data;
        }
    }
    return p->data;
}

int main()
{
    int repeat = 1;
    Node *head = NULL;

    cout << "Linked list created successfully ! \n";
    cout << "\nselect one of the option \n1. create \n2. display \n3.count no of nodes";

    do
    {
        int choice;
        cout << "\nyou chose :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            head = create(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            cout << Middle(head);

        default:
            break;
        }
    } while (repeat);

    return 0;
}